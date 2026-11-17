/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
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
    LOG_TRACE(std::cout << "Expressions::Expression::Expression()" << std::endl);
}

Expressions::Expression::Expression(Expression && Expression)
{
    LOG_TRACE(std::cout << "Expressions::Expression::Expression(Expressions::Expression &&)" << std::endl);
    if(_Term != nullptr)
    {
        assert(_Term->m_Parent == this);
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
    LOG_TRACE(std::cout << "Expressions::Expression::Expression(Expressions::Variable &)" << std::endl);
    _Term->SetParent(this);
}

Expressions::Expression::Expression(std::unique_ptr< Expressions::Term > && Term) :
    _Term(std::move(Term))
{
    LOG_TRACE(std::cout << "Expressions::Expression::Expression(std::unique_ptr< Expressions::Term > &&)" << std::endl);
    _Term->SetParent(this);
}

Expressions::Expression::~Expression(void)
{
    LOG_TRACE(std::cout << "Expressions::Expression::~Expression()" << std::endl);
    assert((_Term == nullptr) || (_Term->m_Parent == this));
}

std::unique_ptr< Expressions::Term > Expressions::Expression::ExtractTerm(void)
{
    LOG_TRACE(std::cout << "std::unique_ptr< Expressions::Term > Expressions::Expression::ExtractTerm()" << std::endl);
    if(_Term != nullptr)
    {
        _Term->SetParent(nullptr);
    }
    
    return std::move(_Term);
}

float Expressions::Expression::GetValue(void)
{
    LOG_TRACE(std::cout << "float Expressions::Expression::GetValue()" << std::endl);
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
    LOG_TRACE(std::cout << "Expressions::Expression::InvalidateValue()" << std::endl);
}

Expressions::Expression & Expressions::Expression::operator=(Expressions::Expression && Expression)
{
    LOG_TRACE(std::cout << "Expressions::Expression::operator=(Expressions::Expression &&)" << std::endl);
    if(_Term != nullptr)
    {
        assert(_Term->m_Parent == this);
        _Term->SetParent(nullptr);
    }
    _Term = Expression.ExtractTerm();
    if(_Term != nullptr)
    {
        _Term->SetParent(this);
    }
    
    return *this;
}
