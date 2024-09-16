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

#ifndef EXPRESSIONS_TERM_H
#define EXPRESSIONS_TERM_H

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
