/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <cassert>
#include <cmath>
#include <memory>

#include <expressions/expression.h>
#include <expressions/term.h>

#include "common.h"
#include "variable_term.h"

Expressions::Expression::Expression()
{
    LOG_TRACE("Expressions::Expression::Expression()");
}

Expressions::Expression::Expression(Expressions::Variable & Variable) :
    _Term(std::make_unique< Expressions::VariableTerm >(&Variable))
{
    LOG_TRACE("Expressions::Expression::Expression(Expressions::Variable &)");
    _Term->SetParent(this);
}

Expressions::Expression::Expression(Expression && Expression) noexcept
{
    LOG_TRACE("Expressions::Expression::Expression(Expressions::Expression &&)");
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

Expressions::Expression::Expression(std::unique_ptr<Expressions::Term> && Term) :
    _Term(std::move(Term))
{
    LOG_TRACE("Expressions::Expression::Expression(std::unique_ptr<Expressions::Term> &&)");
    _Term->SetParent(this);
}

Expressions::Expression::~Expression()
{
    LOG_TRACE("Expressions::Expression::~Expression()");
    assert((_Term == nullptr) || (_Term->m_Parent == this));
}

auto Expressions::Expression::operator=(Expressions::Expression && Expression) noexcept -> Expressions::Expression &
{
    LOG_TRACE("auto Expressions::Expression::operator=(Expressions::Expression &&) -> Expressions::Expression &");
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

auto Expressions::Expression::ExtractTerm() -> std::unique_ptr<Expressions::Term>
{
    LOG_TRACE("auto Expressions::Expression::ExtractTerm() -> std::unique_ptr<Expressions::Term>");
    if(_Term != nullptr)
    {
        _Term->SetParent(nullptr);
    }
    
    return std::move(_Term);
}

auto Expressions::Expression::GetValue() -> float
{
    LOG_TRACE("auto Expressions::Expression::GetValue() -> float");
    if(_Term)
    {
        return _Term->GetValue();
    }
    else
    {
        return NAN;
    }
}

auto Expressions::Expression::InvalidateValue() -> void
{
    LOG_TRACE("auto Expressions::Expression::InvalidateValue() -> void");
}
