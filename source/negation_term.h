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

#ifndef EXPRESSIONS_NEGATION_TERM_H
#define EXPRESSIONS_NEGATION_TERM_H

#include <memory>

#include <expressions/term.h>

namespace Expressions
{
	class NegationTerm : public Expressions::Term
	{
	public:
		NegationTerm(void) = delete;
		NegationTerm(const Expressions::NegationTerm & Term) = delete;
		NegationTerm(Expressions::NegationTerm && Term) = delete;
		NegationTerm & operator=(const Expressions::NegationTerm & Term) = delete;
		NegationTerm & operator=(Expressions::NegationTerm && Term) = delete;
	public:
		NegationTerm(std::unique_ptr< Expressions::Term > && One);
		virtual ~NegationTerm(void);
		virtual float Calculate(void) override;
	private:
		std::unique_ptr< Term > _One;
	};
}

#endif
