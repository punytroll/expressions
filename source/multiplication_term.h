/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__SURCE__MULTIPLICATION_TERM_H
#define EXPRESSIONS__SURCE__MULTIPLICATION_TERM_H

#include <memory>

#include <expressions/term.h>

namespace Expressions
{
    class MultiplicationTerm : public Expressions::Term
    {
    public:
        MultiplicationTerm(void) = delete;
        MultiplicationTerm(const Expressions::MultiplicationTerm & Term) = delete;
        MultiplicationTerm(Expressions::MultiplicationTerm && Term) = delete;
        MultiplicationTerm & operator=(const Expressions::MultiplicationTerm & Term) = delete;
        MultiplicationTerm & operator=(Expressions::MultiplicationTerm && Term) = delete;
    public:
        MultiplicationTerm(std::unique_ptr< Expressions::Term > && One, std::unique_ptr< Expressions::Term > && Two);
        virtual ~MultiplicationTerm(void);
        virtual float Calculate(void) override;
    private:
        std::unique_ptr< Expressions::Term > _One;
        std::unique_ptr< Expressions::Term > _Two;
    };
}

#endif
