/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#include <iostream>

#include <expressions/term_parent.h>

#include "common.h"

Expressions::TermParent::TermParent(void)
{
    LOG_TRACE(std::cout << "Expressions::TermParent::TermParent()" << std::endl);
}

Expressions::TermParent::~TermParent(void)
{
    LOG_TRACE(std::cout << "Expressions::TermParent::~TermParent()" << std::endl);
}
