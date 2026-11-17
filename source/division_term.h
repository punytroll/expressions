/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__SURCE__DIVISION_TERM_H
#define EXPRESSIONS__SURCE__DIVISION_TERM_H

#include <memory>

#include <expressions/term.h>

namespace Expressions
{
    class DivisionTerm : public Expressions::Term
    {
    public:
        DivisionTerm(void) = delete;
        DivisionTerm(const Expressions::DivisionTerm & Term) = delete;
        DivisionTerm(Expressions::DivisionTerm && Term) = delete;
        DivisionTerm & operator=(const Expressions::DivisionTerm & Term) = delete;
        DivisionTerm & operator=(Expressions::DivisionTerm && Term) = delete;
    public:
        DivisionTerm(std::unique_ptr< Expressions::Term > && One, std::unique_ptr< Expressions::Term > && Two);
        virtual ~DivisionTerm(void);
        virtual float Calculate(void) override;
    private:
        std::unique_ptr< Expressions::Term > _One;
        std::unique_ptr< Expressions::Term > _Two;
    };
}

#endif
