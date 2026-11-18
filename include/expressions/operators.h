/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__INCLUDE__EXPRESSIONS__OPERATORS_H
#define EXPRESSIONS__INCLUDE__EXPRESSIONS__OPERATORS_H

namespace Expressions
{
    class Expression;
    class Variable;
    
    namespace Operators
    {
        auto operator""_c(long double Value) -> Expressions::Expression;
        auto constant(float Value) -> Expressions::Expression;
        auto operator-(Expressions::Expression && One) -> Expressions::Expression;
        auto operator-(Expressions::Variable & Variable) -> Expressions::Expression;
        auto operator+(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression;
        auto operator+(Expressions::Variable & One, Expressions::Expression && Two) -> Expressions::Expression;
        auto operator+(Expressions::Variable & One, Expressions::Variable & Two) -> Expressions::Expression;
        auto operator-(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression;
        auto operator-(Expressions::Variable & One, Expressions::Expression && Two) -> Expressions::Expression;
        auto operator*(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression;
        auto operator*(Expressions::Expression && One, Expressions::Variable & Two) -> Expressions::Expression;
        auto operator/(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression;
    }
}

#endif
