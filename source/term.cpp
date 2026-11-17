/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <cassert>

#include <expressions/term.h>

#include "common.h"

Expressions::Term::Term()
{
    LOG_TRACE("Expressions::Term::Term()");
}

Expressions::Term::~Term()
{
    LOG_TRACE("Expressions::Term::~Term()");
}

auto Expressions::Term::GetValue() -> float
{
    LOG_TRACE("auto Expressions::Term::GetValue() -> float");
    if(m_Value.has_value() == false)
    {
        m_Value = Calculate();
    }
    
    return m_Value.value();
}

auto Expressions::Term::InvalidateValue() -> void
{
    LOG_TRACE("auto Expressions::Term::InvalidateValue() -> void");
    m_Value.reset();
    if(m_Parent != nullptr)
    {
        m_Parent->InvalidateValue();
    }
}

auto Expressions::Term::SetParent(Expressions::TermParent * Parent) -> void
{
    LOG_TRACE("auto Expressions::Term::SetParent(Expressions::TermParent *) -> void");
    assert((m_Parent == nullptr) || (Parent == nullptr));
    m_Parent = Parent;
}
