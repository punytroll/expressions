/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__SURCE__NEGATION_TERM_H
#define EXPRESSIONS__SURCE__NEGATION_TERM_H

#include <memory>

#include <expressions/term.h>

namespace Expressions
{
    class NegationTerm : public Expressions::Term
    {
    public:
        NegationTerm(void) = delete;
        NegationTerm(const Expressions::NegationTerm & Term) = delete;
        NegationTerm(Expressions::NegationTerm && Term) = delete;
        NegationTerm & operator=(const Expressions::NegationTerm & Term) = delete;
        NegationTerm & operator=(Expressions::NegationTerm && Term) = delete;
    public:
        NegationTerm(std::unique_ptr< Expressions::Term > && One);
        virtual ~NegationTerm(void);
        virtual float Calculate(void) override;
    private:
        std::unique_ptr< Term > _One;
    };
}

#endif
