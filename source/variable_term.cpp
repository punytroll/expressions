/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <cassert>
#include <cmath>

#include <expressions/variable.h>

#include "common.h"
#include "variable_term.h"

Expressions::VariableTerm::VariableTerm(Expressions::Variable * Variable) :
    _Variable(Variable)
{
    assert(Variable != nullptr);
    LOG_TRACE("Expressions::VariableTerm::VariableTerm(Expressions::Variable *)");
    _Variable->_AddDependentTerm(this);
}

Expressions::VariableTerm::~VariableTerm(void)
{
    LOG_TRACE("Expressions::VariableTerm::~VariableTerm()");
    if(_Variable != nullptr)
    {
        _Variable->_RemoveDependentTerm(this);
    }
}

float Expressions::VariableTerm::Calculate(void)
{
    LOG_TRACE("Expressions::VariableTerm::Calculate()");
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
    LOG_TRACE("Expressions::VariableTerm::InvalidateReference()");
    assert(_Variable != nullptr);
    _Variable = nullptr;
    InvalidateValue();
}
