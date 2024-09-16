/**
 * MIT License
 * 
 * expressions
 * Copyright (c) 2017-2024 Hagen Möbius
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

#include <cassert>
#include <cmath>
#include <iostream>

#include <expressions/expression.h>
#include <expressions/variable.h>

#include "common.h"
#include "variable_term.h"

using namespace Expressions::Operators;

Expressions::Variable::Variable(void)
{
	ON_DEBUG(std::cout << "Expressions::Variable::Variable()" << std::endl);
}

Expressions::Variable::Variable(Expressions::Expression && Expression) :
	_Term(std::move(Expression.ExtractTerm()))
{
	ON_DEBUG(std::cout << "Expressions::Variable::Variable(Expressions::Expression &&)" << std::endl);
	_Term->SetParent(this);
	InvalidateValue();
}

Expressions::Variable::~Variable(void)
{
	ON_DEBUG(std::cout << "Expressions::Variable::~Variable()" << std::endl);
	assert(_Term == nullptr || _Term->_Parent == this);
	while(_DependentVariableTerms.empty() == false)
	{
		auto DependentVariableTerm{_DependentVariableTerms.begin()};
		
		(*DependentVariableTerm)->InvalidateReference();
		_DependentVariableTerms.erase(DependentVariableTerm);
	}
}

float Expressions::Variable::GetValue(void)
{
	ON_DEBUG(std::cout << "Expressions::Variable::GetValue()" << std::endl);
	if(_Term != nullptr)
	{
		return _Term->GetValue();
	}
	else
	{
		return std::nanf("");
	}
}

void Expressions::Variable::InvalidateValue(void)
{
	ON_DEBUG(std::cout << "Expressions::Variable::InvalidateValue()" << std::endl);
	for(auto & DependentVariableTerm : _DependentVariableTerms)
	{
		ON_DEBUG(std::cout << "    Notifying one dependent variable term that we changed." << std::endl);
		DependentVariableTerm->InvalidateValue();
	}
}

void Expressions::Variable::Reset(void)
{
	ON_DEBUG(std::cout << "Expressions::Variable::Reset()" << std::endl);
	float OldValue{std::nanf("")};
	
	if(_Term != nullptr)
	{
		OldValue = _Term->GetValue();
		assert(_Term->_Parent == this);
		_Term->SetParent(nullptr);
	}
	_Term = nullptr;
	if(std::isnan(OldValue) == false)
	{
		InvalidateValue();
	}
}

void Expressions::Variable::SetExpression(Expressions::Expression && Expression)
{
	ON_DEBUG(std::cout << "Expressions::Variable::SetExpression(Expressions::Expression &&)" << std::endl);
	
	float OldValue{std::nanf("")};
	float NewValue{std::nanf("")};
	
	if(_Term != nullptr)
	{
		OldValue = _Term->GetValue();
		assert(_Term->_Parent == this);
		_Term->SetParent(nullptr);
	}
	_Term = Expression.ExtractTerm();
	if(_Term != nullptr)
	{
		_Term->SetParent(this);
		NewValue = _Term->GetValue();
	}
	if(OldValue != NewValue)
	{
		InvalidateValue();
	}
}

void Expressions::Variable::_AddDependentTerm(Expressions::VariableTerm * DependentVariableTerm)
{
	_DependentVariableTerms.insert(DependentVariableTerm);
}

void Expressions::Variable::_RemoveDependentTerm(Expressions::VariableTerm * DependentVariableTerm)
{
	_DependentVariableTerms.erase(DependentVariableTerm);
}

Expressions::Variable & Expressions::Variable::operator=(Expressions::Variable & Variable)
{
	ON_DEBUG(std::cout << "Expressions::Variable & Expressions::Variable::operator=(Expressions::Variable &)" << std::endl);
	SetExpression(Expressions::Expression(Variable));
	
	return *this;
}

Expressions::Variable & Expressions::Variable::operator=(Expressions::Expression && Expression)
{
	ON_DEBUG(std::cout << "Expressions::Variable & Expressions::Variable::operator=(Expressions::Expression &&)" << std::endl);
	SetExpression(std::move(Expression));
	
	return *this;
}
