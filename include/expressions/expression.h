/**
 * MIT License
 * 
 * expressions
 * Copyright (c) 2017-2024 Hagen Möbius
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

#ifndef EXPRESSIONS_EXPRESSION_H
#define EXPRESSIONS_EXPRESSION_H

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
		friend Expressions::Expression Expressions::Operators::operator"" _c(long double Value);
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
