/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <cassert>
#include <iostream>

#include <expressions/term.h>

#include "common.h"

Expressions::Term::Term()
{
    LOG_TRACE(std::cout << "Expressions::Term::Term()" << std::endl);
}

Expressions::Term::~Term()
{
    LOG_TRACE(std::cout << "Expressions::Term::~Term()" << std::endl);
}

auto Expressions::Term::GetValue() -> float
{
    LOG_TRACE(std::cout << "auto Expressions::Term::GetValue() -> float" << std::endl);
    if(m_Value.has_value() == false)
    {
        m_Value = Calculate();
    }
    
    return m_Value.value();
}

auto Expressions::Term::InvalidateValue() -> void
{
    LOG_TRACE(std::cout << "auto Expressions::Term::InvalidateValue() -> void" << std::endl);
    m_Value.reset();
    if(m_Parent != nullptr)
    {
        m_Parent->InvalidateValue();
    }
}

auto Expressions::Term::SetParent(Expressions::TermParent * Parent) -> void
{
    LOG_TRACE(std::cout << "auto Expressions::Term::SetParent(Expressions::TermParent *) -> void" << std::endl);
    assert((m_Parent == nullptr) || (Parent == nullptr));
    m_Parent = Parent;
}
