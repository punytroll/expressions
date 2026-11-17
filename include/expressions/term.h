/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__INCLUDE__EXPRESSIONS__TERM_H
#define EXPRESSIONS__INCLUDE__EXPRESSIONS__TERM_H

#include <expressions/term_parent.h>

namespace Expressions
{
    class Expression;
    class Variable;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    // As part of the "expression" library, the Term class is the abstract base class of all terms   //
    // in expressions.                                                                               //
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    class Term : public TermParent
    {
    public:
        friend class Expressions::Expression;
        friend class Expressions::Variable;
    public:
        Term(const Expressions::Term & Term) = delete;
        Term(Expressions::Term && Term) = delete;
        Term & operator=(const Expressions::Term & Term) = delete;
        Term & operator=(Expressions::Term && Term) = delete;
    public:
        virtual ~Term(void);
        float GetValue(void);
        virtual float Calculate(void) = 0;
        virtual void InvalidateValue(void) override;
        void SetParent(Expressions::TermParent * Parent);
    protected:
        Term(void);
    private:
        Expressions::TermParent * _Parent;
        float * _Value;
    }; 
}

#endif
