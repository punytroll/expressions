/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
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
    LOG_TRACE(std::cout << "Expressions::Variable::Variable()" << std::endl);
}

Expressions::Variable::Variable(Expressions::Expression && Expression) :
    _Term(std::move(Expression.ExtractTerm()))
{
    LOG_TRACE(std::cout << "Expressions::Variable::Variable(Expressions::Expression &&)" << std::endl);
    _Term->SetParent(this);
    InvalidateValue();
}

Expressions::Variable::~Variable(void)
{
    LOG_TRACE(std::cout << "Expressions::Variable::~Variable()" << std::endl);
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
    LOG_TRACE(std::cout << "Expressions::Variable::GetValue()" << std::endl);
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
    LOG_TRACE(std::cout << "Expressions::Variable::InvalidateValue()" << std::endl);
    for(auto & DependentVariableTerm : _DependentVariableTerms)
    {
        LOG_TRACE(std::cout << "    Notifying one dependent variable term that we changed." << std::endl);
        DependentVariableTerm->InvalidateValue();
    }
}

void Expressions::Variable::Reset(void)
{
    LOG_TRACE(std::cout << "Expressions::Variable::Reset()" << std::endl);
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
    LOG_TRACE(std::cout << "Expressions::Variable::SetExpression(Expressions::Expression &&)" << std::endl);
    
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
    LOG_TRACE(std::cout << "Expressions::Variable & Expressions::Variable::operator=(Expressions::Variable &)" << std::endl);
    SetExpression(Expressions::Expression(Variable));
    
    return *this;
}

Expressions::Variable & Expressions::Variable::operator=(Expressions::Expression && Expression)
{
    LOG_TRACE(std::cout << "Expressions::Variable & Expressions::Variable::operator=(Expressions::Expression &&)" << std::endl);
    SetExpression(std::move(Expression));
    
    return *this;
}
