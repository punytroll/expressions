/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include "common.h"
#include "multiplication_term.h"

Expressions::MultiplicationTerm::MultiplicationTerm(std::unique_ptr< Expressions::Term > && One, std::unique_ptr< Expressions::Term > && Two) :
    _One(std::move(One)),
    _Two(std::move(Two))
{
    LOG_TRACE("Expressions::MultiplicationTerm::MultiplicationTerm(std::unique_ptr<Expressions::Term> &&, std::unique_ptr<Expressions::Term> &&)");
    _One->SetParent(this);
    _Two->SetParent(this);
}

Expressions::MultiplicationTerm::~MultiplicationTerm(void)
{
    LOG_TRACE("Expressions::MultiplicationTerm::~MultiplicationTerm()");
}

float Expressions::MultiplicationTerm::Calculate(void)
{
    LOG_TRACE("auto Expressions::MultiplicationTerm::Calculate() -> float");
    
    return _One->GetValue() * _Two->GetValue();
}
