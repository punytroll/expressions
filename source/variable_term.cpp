/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <cassert>
#include <cmath>
#include <iostream>

#include <expressions/variable.h>

#include "common.h"
#include "variable_term.h"

Expressions::VariableTerm::VariableTerm(Expressions::Variable * Variable) :
    _Variable(Variable)
{
    assert(Variable != nullptr);
    LOG_TRACE(std::cout << "Expressions::VariableTerm::VariableTerm(Expressions::Variable *)" << std::endl);
    _Variable->_AddDependentTerm(this);
}

Expressions::VariableTerm::~VariableTerm(void)
{
    LOG_TRACE(std::cout << "Expressions::VariableTerm::~VariableTerm()" << std::endl);
    if(_Variable != nullptr)
    {
        _Variable->_RemoveDependentTerm(this);
    }
}

float Expressions::VariableTerm::Calculate(void)
{
    LOG_TRACE(std::cout << "Expressions::VariableTerm::Calculate()" << std::endl);
    if(_Variable != nullptr)
    {
        return _Variable->GetValue();
    }
    else
    {
        return std::nanf("");
    }
}

void Expressions::VariableTerm::InvalidateReference(void)
{
    LOG_TRACE(std::cout << "Expressions::VariableTerm::InvalidateReference()" << std::endl);
    assert(_Variable != nullptr);
    _Variable = nullptr;
    InvalidateValue();
}
