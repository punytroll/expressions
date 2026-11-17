/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <cassert>
#include <iostream>

#include "common.h"
#include "constant_term.h"

Expressions::ConstantTerm::ConstantTerm(float Value) :
    _Value(Value)
{
    LOG_TRACE(std::cout << "Expressions::ConstantTerm::ConstantTerm(float)" << std::endl);
}

Expressions::ConstantTerm::~ConstantTerm(void)
{
    LOG_TRACE(std::cout << "Expressions::ConstantTerm::~ConstantTerm()" << std::endl);
}

float Expressions::ConstantTerm::Calculate(void)
{
    LOG_TRACE(std::cout << "Expressions::ConstantTerm::Calculate()" << std::endl);
    
    return _Value;
}
