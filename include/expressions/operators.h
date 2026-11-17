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
        Expressions::Expression operator""_c(long double Value);
        Expressions::Expression constant(double Value);
        Expressions::Expression operator-(Expressions::Expression && One);
        Expressions::Expression operator-(Expressions::Variable & Variable);
        Expressions::Expression operator+(Expressions::Expression && One, Expressions::Expression && Two);
        Expressions::Expression operator+(Expressions::Variable & One, Expressions::Expression && Two);
        Expressions::Expression operator+(Expressions::Variable & One, Expressions::Variable & Two);
        Expressions::Expression operator-(Expressions::Expression && One, Expressions::Expression && Two);
        Expressions::Expression operator-(Expressions::Variable & One, Expressions::Expression && Two);
        Expressions::Expression operator*(Expressions::Expression && One, Expressions::Expression && Two);
        Expressions::Expression operator/(Expressions::Expression && One, Expressions::Expression && Two);
    }
}

#endif
