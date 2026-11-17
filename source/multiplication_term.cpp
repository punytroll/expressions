/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <iostream>

#include "common.h"
#include "multiplication_term.h"

Expressions::MultiplicationTerm::MultiplicationTerm(std::unique_ptr< Expressions::Term > && One, std::unique_ptr< Expressions::Term > && Two) :
    _One(std::move(One)),
    _Two(std::move(Two))
{
    LOG_TRACE(std::cout << "Expressions::MultiplicationTerm::MultiplicationTerm(std::unique_ptr< Expressions::Term > &&, std::unique_ptr< Expressions::Term > &&)" << std::endl);
    _One->SetParent(this);
    _Two->SetParent(this);
}

Expressions::MultiplicationTerm::~MultiplicationTerm(void)
{
    LOG_TRACE(std::cout << "Expressions::MultiplicationTerm::~MultiplicationTerm()" << std::endl);
}

float Expressions::MultiplicationTerm::Calculate(void)
{
    LOG_TRACE(std::cout << "Expressions::MultiplicationTerm::Calculate()" << std::endl);
    
    return _One->GetValue() * _Two->GetValue();
}
