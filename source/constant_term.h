/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__SURCE__CONSTANT_TERM_H
#define EXPRESSIONS__SURCE__CONSTANT_TERM_H

#include <expressions/term.h>

namespace Expressions
{
    class ConstantTerm : public Expressions::Term
    {
    public:
        ConstantTerm(void) = delete;
        ConstantTerm(const ConstantTerm & Term) = delete;
        ConstantTerm(ConstantTerm && Term) = delete;
        ConstantTerm & operator=(const ConstantTerm & Term) = delete;
        ConstantTerm & operator=(ConstantTerm && Term) = delete;
    public:
        ConstantTerm(float Value);
        virtual ~ConstantTerm(void);
        virtual float Calculate(void) override;
    private:
        float _Value;
    };
}

#endif
