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
        friend auto Expressions::Operators::operator""_c(long double Value) -> Expressions::Expression;
        friend auto Expressions::Operators::constant(float Value) -> Expressions::Expression;
        friend auto Expressions::Operators::operator-(Expressions::Expression && One) -> Expressions::Expression;
        friend auto Expressions::Operators::operator-(Expressions::Variable & Variable) -> Expressions::Expression;
        friend auto Expressions::Operators::operator+(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression;
        friend auto Expressions::Operators::operator+(Expressions::Variable & One, Expressions::Expression && Two) -> Expressions::Expression;
        friend auto Expressions::Operators::operator+(Expressions::Variable & One, Expressions::Variable & Two) -> Expressions::Expression;
        friend auto Expressions::Operators::operator-(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression;
        friend auto Expressions::Operators::operator-(Expressions::Variable & One, Expressions::Expression && Two) -> Expressions::Expression;
        friend auto Expressions::Operators::operator*(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression;
        friend auto Expressions::Operators::operator*(Expressions::Expression && One, Expressions::Variable & Two) -> Expressions::Expression;
        friend auto Expressions::Operators::operator/(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression;
        
    public:
        Expression();
        Expression(Expressions::Expression && Expression) noexcept;
        explicit Expression(Expressions::Variable & Variable);
        Expression(Expressions::Expression const & Expression) = delete;
        ~Expression();
        auto operator=(Expressions::Expression && Expression) noexcept -> Expressions::Expression &;
        auto operator=(Expressions::Expression const & Expression) -> Expressions::Expression & = delete;
        auto ExtractTerm() -> std::unique_ptr<Expressions::Term>;
        auto GetValue() -> float;
        auto InvalidateValue() -> void override;
        
    private:
        explicit Expression(std::unique_ptr<Expressions::Term> && Term);
        
        std::unique_ptr< Expressions::Term > _Term;
    };
}

#endif
