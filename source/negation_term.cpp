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

#include <iostream>

#include "common.h"
#include "negation_term.h"

Expressions::NegationTerm::NegationTerm(std::unique_ptr< Expressions::Term > && One) :
	_One(std::move(One))
{
	ON_DEBUG(std::cout << "Expressions::NegationTerm::NegationTerm(std::unique_ptr< Expressions::Term > &&)" << std::endl);
	_One->SetParent(this);
}

Expressions::NegationTerm::~NegationTerm(void)
{
	ON_DEBUG(std::cout << "Expressions::NegationTerm::~NegationTerm()" << std::endl);
}

float Expressions::NegationTerm::Calculate(void)
{
	ON_DEBUG(std::cout << "Expressions::NegationTerm::Calculate()" << std::endl);
	
	return -_One->GetValue();
}
