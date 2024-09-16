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
#include <memory>

#include <expressions/expression.h>
#include <expressions/term.h>

#include "common.h"
#include "variable_term.h"

Expressions::Expression::Expression(void)
{
	ON_DEBUG(std::cout << "Expressions::Expression::Expression()" << std::endl);
}

Expressions::Expression::Expression(Expression && Expression)
{
	ON_DEBUG(std::cout << "Expressions::Expression::Expression(Expressions::Expression &&)" << std::endl);
	if(_Term != nullptr)
	{
		assert(_Term->_Parent == this);
		_Term->SetParent(nullptr);
	}
	_Term = Expression.ExtractTerm();
	if(_Term != nullptr)
	{
		_Term->SetParent(this);
	}
}

Expressions::Expression::Expression(Expressions::Variable & Variable) :
	_Term(std::make_unique< Expressions::VariableTerm >(&Variable))
{
	ON_DEBUG(std::cout << "Expressions::Expression::Expression(Expressions::Variable &)" << std::endl);
	_Term->SetParent(this);
}

Expressions::Expression::Expression(std::unique_ptr< Expressions::Term > && Term) :
	_Term(std::move(Term))
{
	ON_DEBUG(std::cout << "Expressions::Expression::Expression(std::unique_ptr< Expressions::Term > &&)" << std::endl);
	_Term->SetParent(this);
}

Expressions::Expression::~Expression(void)
{
	ON_DEBUG(std::cout << "Expressions::Expression::~Expression()" << std::endl);
	assert(_Term == nullptr || _Term->_Parent == this);
}

std::unique_ptr< Expressions::Term > Expressions::Expression::ExtractTerm(void)
{
	ON_DEBUG(std::cout << "std::unique_ptr< Expressions::Term > Expressions::Expression::ExtractTerm()" << std::endl);
	if(_Term != nullptr)
	{
		_Term->SetParent(nullptr);
	}
	
	return std::move(_Term);
}

float Expressions::Expression::GetValue(void)
{
	ON_DEBUG(std::cout << "float Expressions::Expression::GetValue()" << std::endl);
	if(_Term)
	{
		return _Term->GetValue();
	}
	else
	{
		return NAN;
	}
}

void Expressions::Expression::InvalidateValue(void)
{
	ON_DEBUG(std::cout << "Expressions::Expression::InvalidateValue()" << std::endl);
}

Expressions::Expression & Expressions::Expression::operator=(Expressions::Expression && Expression)
{
	ON_DEBUG(std::cout << "Expressions::Expression::operator=(Expressions::Expression &&)" << std::endl);
	if(_Term != nullptr)
	{
		assert(_Term->_Parent == this);
		_Term->SetParent(nullptr);
	}
	_Term = Expression.ExtractTerm();
	if(_Term != nullptr)
	{
		_Term->SetParent(this);
	}
	
	return *this;
}
