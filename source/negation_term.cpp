/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <iostream>

#include "common.h"
#include "negation_term.h"

Expressions::NegationTerm::NegationTerm(std::unique_ptr< Expressions::Term > && One) :
    _One(std::move(One))
{
    LOG_TRACE(std::cout << "Expressions::NegationTerm::NegationTerm(std::unique_ptr< Expressions::Term > &&)" << std::endl);
    _One->SetParent(this);
}

Expressions::NegationTerm::~NegationTerm(void)
{
    LOG_TRACE(std::cout << "Expressions::NegationTerm::~NegationTerm()" << std::endl);
}

float Expressions::NegationTerm::Calculate(void)
{
    LOG_TRACE(std::cout << "Expressions::NegationTerm::Calculate()" << std::endl);
    
    return -_One->GetValue();
}
