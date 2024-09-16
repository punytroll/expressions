/**
 * MIT License
 * 
 * expressions
 * Copyright (c) 2017-2024 Hagen M�bius
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

#ifndef EXPRESSIONS_OPERATORS_H
#define EXPRESSIONS_OPERATORS_H

namespace Expressions
{
	class Expression;
	class Variable;
	
	namespace Operators
	{
		Expressions::Expression operator"" _c(long double Value);
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
