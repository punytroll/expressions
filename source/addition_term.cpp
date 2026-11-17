/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <iostream>

#include "addition_term.h"
#include "common.h"

Expressions::AdditionTerm::AdditionTerm(std::unique_ptr< Expressions::Term > && One, std::unique_ptr< Expressions::Term > && Two) :
    _One(std::move(One)),
    _Two(std::move(Two))
{
    LOG_TRACE(std::cout << "Expressions::AdditionTerm::AdditionTerm(std::unique_ptr< Expressions::Term > &&, std::unique_ptr< Expressions::Term > &&)" << std::endl);
    _One->SetParent(this);
    _Two->SetParent(this);
}

Expressions::AdditionTerm::~AdditionTerm(void)
{
    LOG_TRACE(std::cout << "Expressions::AdditionTerm::~AdditionTerm()" << std::endl);
}

float Expressions::AdditionTerm::Calculate(void)
{
    LOG_TRACE(std::cout << "Expressions::AdditionTerm::Calculate()" << std::endl);
    
    return _One->GetValue() + _Two->GetValue();
}
