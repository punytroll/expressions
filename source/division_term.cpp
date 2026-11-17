/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include "common.h"
#include "division_term.h"

Expressions::DivisionTerm::DivisionTerm(std::unique_ptr< Expressions::Term > && One, std::unique_ptr< Expressions::Term > && Two) :
    _One(std::move(One)),
    _Two(std::move(Two))
{
    LOG_TRACE("Expressions::DivisionTerm::DivisionTerm(std::unique_ptr<Expressions::Term> &&, std::unique_ptr<Expressions::Term> &&)");
    _One->SetParent(this);
    _Two->SetParent(this);
}

Expressions::DivisionTerm::~DivisionTerm(void)
{
    LOG_TRACE("Expressions::DivisionTerm::~DivisionTerm()");
}

float Expressions::DivisionTerm::Calculate(void)
{
    LOG_TRACE("auto Expressions::DivisionTerm::Calculate() -> float");
    
    return _One->GetValue() / _Two->GetValue();
}
