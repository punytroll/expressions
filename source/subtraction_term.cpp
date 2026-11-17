/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <iostream>

#include "common.h"
#include "subtraction_term.h"

Expressions::SubtractionTerm::SubtractionTerm(std::unique_ptr< Expressions::Term > && One, std::unique_ptr< Expressions::Term > && Two) :
    _One(std::move(One)),
    _Two(std::move(Two))
{
    LOG_TRACE(std::cout << "Expressions::SubtractionTerm::SubtractionTerm(std::unique_ptr< Expressions::Term > &&, std::unique_ptr< Expressions::Term > &&)" << std::endl);
    _One->SetParent(this);
    _Two->SetParent(this);
}

Expressions::SubtractionTerm::~SubtractionTerm(void)
{
    LOG_TRACE(std::cout << "Expressions::SubtractionTerm::~SubtractionTerm()" << std::endl);
}

float Expressions::SubtractionTerm::Calculate(void)
{
    LOG_TRACE(std::cout << "Expressions::SubtractionTerm::Calculate()" << std::endl);
    
    return _One->GetValue() - _Two->GetValue();
}
