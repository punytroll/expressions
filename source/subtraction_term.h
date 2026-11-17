/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__SURCE__SUBTRACTION_TERM_H
#define EXPRESSIONS__SURCE__SUBTRACTION_TERM_H

#include <memory>

#include <expressions/term.h>

namespace Expressions
{
    class SubtractionTerm : public Expressions::Term
    {
    public:
        SubtractionTerm(void) = delete;
        SubtractionTerm(const Expressions::SubtractionTerm & Term) = delete;
        SubtractionTerm(Expressions::SubtractionTerm && Term) = delete;
        SubtractionTerm & operator=(const Expressions::SubtractionTerm & Term) = delete;
        SubtractionTerm & operator=(Expressions::SubtractionTerm && Term) = delete;
    public:
        SubtractionTerm(std::unique_ptr< Expressions::Term > && One, std::unique_ptr< Expressions::Term > && Two);
        virtual ~SubtractionTerm(void);
        virtual float Calculate(void) override;
    private:
        std::unique_ptr< Expressions::Term > _One;
        std::unique_ptr< Expressions::Term > _Two;
    };
}

#endif
