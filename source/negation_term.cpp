/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include "common.h"
#include "negation_term.h"

Expressions::NegationTerm::NegationTerm(std::unique_ptr< Expressions::Term > && One) :
    _One(std::move(One))
{
    LOG_TRACE("Expressions::NegationTerm::NegationTerm(std::unique_ptr<Expressions::Term> &&)");
    _One->SetParent(this);
}

Expressions::NegationTerm::~NegationTerm(void)
{
    LOG_TRACE("Expressions::NegationTerm::~NegationTerm()");
}

float Expressions::NegationTerm::Calculate(void)
{
    LOG_TRACE("auto Expressions::NegationTerm::Calculate() -> float");
    
    return -_One->GetValue();
}
