/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__SURCE__ADDITION_TERM_H
#define EXPRESSIONS__SURCE__ADDITION_TERM_H

#include <memory>

#include <expressions/term.h>

namespace Expressions
{
    class AdditionTerm : public Expressions::Term
    {
    public:
        AdditionTerm(void) = delete;
        AdditionTerm(const Expressions::AdditionTerm & Term) = delete;
        AdditionTerm(Expressions::AdditionTerm && Term) = delete;
        AdditionTerm & operator=(const Expressions::AdditionTerm & Term) = delete;
        AdditionTerm & operator=(Expressions::AdditionTerm && Term) = delete;
    public:
        AdditionTerm(std::unique_ptr< Expressions::Term > && One, std::unique_ptr< Expressions::Term > && Two);
        virtual ~AdditionTerm(void);
        virtual float Calculate(void) override;
    private:
        std::unique_ptr< Expressions::Term > _One;
        std::unique_ptr< Expressions::Term > _Two;
    };
}

#endif
