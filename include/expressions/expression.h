/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__INCLUDE__EXPRESSIONS__EXPRESSION_H
#define EXPRESSIONS__INCLUDE__EXPRESSIONS__EXPRESSION_H

#include <memory>

#include <expressions/operators.h>
#include <expressions/term_parent.h>

namespace Expressions
{
    class Term;
    class Variable;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    // As part of the expression library, the Expression class is a shallow wrapper class around any //
    // term. It is mainly used to hide the implementation detail of the unique_ptr for terms.        //
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    class Expression : public TermParent
    {
    public:
        friend class Expressions::Variable;
        friend Expressions::Expression Expressions::Operators::operator""_c(long double Value);
        friend Expressions::Expression Expressions::Operators::constant(double Value);
        friend Expressions::Expression Expressions::Operators::operator-(Expressions::Expression && One);
        friend Expressions::Expression Expressions::Operators::operator-(Expressions::Variable & Variable);
        friend Expressions::Expression Expressions::Operators::operator+(Expressions::Expression && One, Expressions::Expression && Two);
        friend Expressions::Expression Expressions::Operators::operator+(Expressions::Variable & One, Expressions::Expression && Two);
        friend Expressions::Expression Expressions::Operators::operator+(Expressions::Variable & One, Expressions::Variable & Two);
        friend Expressions::Expression Expressions::Operators::operator-(Expressions::Expression && One, Expressions::Expression && Two);
        friend Expressions::Expression Expressions::Operators::operator-(Expressions::Variable & One, Expressions::Expression && Two);
        friend Expressions::Expression Expressions::Operators::operator*(Expressions::Expression && One, Expressions::Expression && Two);
        friend Expressions::Expression Expressions::Operators::operator/(Expressions::Expression && One, Expressions::Expression && Two);
    public:
        Expression(const Expressions::Expression & Expression) = delete;
        Expressions::Expression & operator=(const Expressions::Expression & Expression) = delete;
    public:
        Expression(void);
        Expression(Expressions::Variable & Variable);
        Expression(Expressions::Expression && Expression);
        ~Expression(void);
        std::unique_ptr< Expressions::Term > ExtractTerm(void);
        float GetValue(void);
        virtual void InvalidateValue(void);
        Expressions::Expression & operator=(Expressions::Expression && Expression);
    private:
        Expression(std::unique_ptr< Expressions::Term > && Term);
        std::unique_ptr< Expressions::Term > _Term;
    };
}

#endif
