/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <cassert>
#include <iostream>

#include <expressions/term.h>

#include "common.h"

Expressions::Term::Term(void) :
    _Parent(nullptr),
    _Value(nullptr)
{
    LOG_TRACE(std::cout << "Expressions::Term::Term()" << std::endl);
}

Expressions::Term::~Term(void)
{
    delete _Value;
    _Value = nullptr;
    LOG_TRACE(std::cout << "Expressions::Term::~Term()" << std::endl);
}

float Expressions::Term::GetValue(void)
{
    LOG_TRACE(std::cout << "Expressions::Term::GetValue()" << std::endl);
    if(_Value == nullptr)
    {
        _Value = new float(Calculate());
    }
    assert(_Value != nullptr);
    
    return *_Value;
}

void Expressions::Term::InvalidateValue(void)
{
    LOG_TRACE(std::cout << "Expressions::Term::InvalidateValue()" << std::endl);
    delete _Value;
    _Value = nullptr;
    if(_Parent != nullptr)
    {
        _Parent->InvalidateValue();
    }
}

void Expressions::Term::SetParent(Expressions::TermParent * Parent)
{
    LOG_TRACE(std::cout << "Expressions::Term::SetParent(Expressions::TermParent *)" << std::endl);
    assert(_Parent == nullptr || Parent == nullptr);
    _Parent = Parent;
}
