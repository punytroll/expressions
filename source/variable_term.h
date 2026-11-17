/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__SURCE__VARIABLE_TERM_H
#define EXPRESSIONS__SURCE__VARIABLE_TERM_H

#include <expressions/term.h>

namespace Expressions
{
    class Variable;
    
    class VariableTerm : public Expressions::Term
    {
    public:
        VariableTerm(Expressions::Variable * Variable);
        ~VariableTerm(void);
        virtual float Calculate(void) override;
        void InvalidateReference(void);
    private:
        Expressions::Variable * _Variable;
    };
}

#endif
