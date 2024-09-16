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

#ifndef EXPRESSIONS_ADDITION_TERM_H
#define EXPRESSIONS_ADDITION_TERM_H

#include <memory>

#include <expressions/term.h>

namespace Expressions
{
	class AdditionTerm : public Expressions::Term
	{
	public:
		AdditionTerm(void) = delete;
		AdditionTerm(const Expressions::AdditionTerm & Term) = delete;
		AdditionTerm(Expressions::AdditionTerm && Term) = delete;
		AdditionTerm & operator=(const Expressions::AdditionTerm & Term) = delete;
		AdditionTerm & operator=(Expressions::AdditionTerm && Term) = delete;
	public:
		AdditionTerm(std::unique_ptr< Expressions::Term > && One, std::unique_ptr< Expressions::Term > && Two);
		virtual ~AdditionTerm(void);
		virtual float Calculate(void) override;
	private:
		std::unique_ptr< Expressions::Term > _One;
		std::unique_ptr< Expressions::Term > _Two;
	};
}

#endif
