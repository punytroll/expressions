/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include "common.h"
#include "constant_term.h"

Expressions::ConstantTerm::ConstantTerm(float Value) :
    _Value(Value)
{
    LOG_TRACE("Expressions::ConstantTerm::ConstantTerm(float)");
}

Expressions::ConstantTerm::~ConstantTerm(void)
{
    LOG_TRACE("Expressions::ConstantTerm::~ConstantTerm()");
}

float Expressions::ConstantTerm::Calculate(void)
{
    LOG_TRACE("auto Expressions::ConstantTerm::Calculate() -> float");
    
    return _Value;
}
