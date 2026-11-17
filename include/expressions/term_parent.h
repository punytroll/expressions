/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__INCLUDE__EXPRESSIONS__TERM_PARENT_H
#define EXPRESSIONS__INCLUDE__EXPRESSIONS__TERM_PARENT_H

namespace Expressions
{
    class TermParent
    {
    public:
        TermParent(void);
        virtual ~TermParent(void);
        virtual void InvalidateValue(void) = 0;
    };
}

#endif
