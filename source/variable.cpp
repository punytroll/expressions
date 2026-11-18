/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <cassert>
#include <cmath>

#include <expressions/expression.h>
#include <expressions/variable.h>

#include "common.h"
#include "variable_term.h"

using namespace Expressions::Operators;

Expressions::Variable::Variable(void)
{
    LOG_TRACE("Expressions::Variable::Variable()");
}

Expressions::Variable::Variable(Expressions::Expression && Expression) :
    _Term(std::move(Expression.ExtractTerm()))
{
    LOG_TRACE("Expressions::Variable::Variable(Expressions::Expression &&)");
    _Term->SetParent(this);
    //~ InvalidateValue();
}

Expressions::Variable::~Variable(void)
{
    LOG_TRACE("Expressions::Variable::~Variable()");
    assert((_Term == nullptr) || (_Term->m_Parent == this));
    while(_DependentVariableTerms.empty() == false)
    {
        auto DependentVariableTerm{_DependentVariableTerms.begin()};
        
        (*DependentVariableTerm)->InvalidateReference();
        _DependentVariableTerms.erase(DependentVariableTerm);
    }
}

float Expressions::Variable::GetValue(void)
{
    LOG_TRACE("auto Expressions::Variable::GetValue() -> float");
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
    LOG_TRACE("auto Expressions::Variable::InvalidateValue() -> void");
    for(auto & DependentVariableTerm : _DependentVariableTerms)
    {
        LOG_TRACE("    Notifying one dependent variable term that we changed.");
        DependentVariableTerm->InvalidateValue();
    }
}

void Expressions::Variable::Reset(void)
{
    LOG_TRACE("auto Expressions::Variable::Reset() -> void");
    float OldValue{std::nanf("")};
    
    if(_Term != nullptr)
    {
        OldValue = _Term->GetValue();
        assert(_Term->m_Parent == this);
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
    LOG_TRACE("auto Expressions::Variable::SetExpression(Expressions::Expression &&) -> void");
    
    float OldValue{std::nanf("")};
    float NewValue{std::nanf("")};
    
    if(_Term != nullptr)
    {
        OldValue = _Term->GetValue();
        assert(_Term->m_Parent == this);
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
    LOG_TRACE("auto Expressions::Variable::operator=(Expressions::Variable &) -> Expressions::Variable &");
    if(this != std::addressof(Variable))
    {
        SetExpression(Expressions::Expression{Variable});
    }
    
    return *this;
}

Expressions::Variable & Expressions::Variable::operator=(Expressions::Expression && Expression)
{
    LOG_TRACE("auto Expressions::Variable::operator=(Expressions::Expression &&) -> Expressions::Variable &");
    SetExpression(std::move(Expression));
    
    return *this;
}
