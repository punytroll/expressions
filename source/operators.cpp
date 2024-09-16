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

#include <iostream>

#include <expressions/expression.h>
#include <expressions/operators.h>

#include "addition_term.h"
#include "common.h"
#include "constant_term.h"
#include "division_term.h"
#include "multiplication_term.h"
#include "negation_term.h"
#include "subtraction_term.h"
#include "variable_term.h"

Expressions::Expression Expressions::Operators::operator"" _c(long double Value)
{
	ON_DEBUG(std::cout << "Expressions::Operators::operator\"\" _c(long double)" << std::endl);
	
	return Expressions::Expression(std::make_unique< Expressions::ConstantTerm >(Value));
}

Expressions::Expression Expressions::Operators::constant(double Value)
{
	ON_DEBUG(std::cout << "Expressions::Operators::constant(double)" << std::endl);
	
	return Expressions::Expression(std::make_unique< Expressions::ConstantTerm >(Value));
}

Expressions::Expression Expressions::Operators::operator-(Expressions::Expression && One)
{
	ON_DEBUG(std::cout << "Expressions::Operators::operator-(Expressions::Expression &&)" << std::endl);
	
	return Expressions::Expression(std::make_unique< Expressions::NegationTerm >(std::move(One.ExtractTerm())));
}

Expressions::Expression Expressions::Operators::operator-(Expressions::Variable & Variable)
{
	ON_DEBUG(std::cout << "Expressions::Operators::operator-(Expressions::Variable &)" << std::endl);
	
	return -Expressions::Expression(std::make_unique< Expressions::VariableTerm >(&Variable));
}

Expressions::Expression Expressions::Operators::operator+(Expressions::Expression && One, Expressions::Expression && Two)
{
	ON_DEBUG(std::cout << "Expressions::Operators::operator+(Expressions::Expression &&, Expressions::Expression &&)" << std::endl);
	
	return Expressions::Expression(std::make_unique< Expressions::AdditionTerm >(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm())));
}

Expressions::Expression Expressions::Operators::operator+(Expressions::Variable & One, Expressions::Expression && Two)
{
	ON_DEBUG(std::cout << "Expressions::Operators::operator+(Expressions::Variable &, Expressions::Expression &&)" << std::endl);
	
	return Expressions::Expression(std::make_unique< Expressions::VariableTerm >(&One)) + std::move(Two.ExtractTerm());
}

Expressions::Expression Expressions::Operators::operator+(Expressions::Variable & One, Expressions::Variable & Two)
{
	ON_DEBUG(std::cout << "Expressions::Operators::operator+(Expressions::Variable &, Expressions::Variable &)" << std::endl);
	
	return Expressions::Expression(std::make_unique< Expressions::VariableTerm >(&One)) + Expressions::Expression(std::make_unique< Expressions::VariableTerm >(&Two));
}

Expressions::Expression Expressions::Operators::operator-(Expressions::Expression && One, Expressions::Expression && Two)
{
	ON_DEBUG(std::cout << "Expressions::Operators::operator+(Expressions::Expression &&, Expressions::Expression &&)" << std::endl);
	
	return Expressions::Expression(std::make_unique< Expressions::SubtractionTerm >(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm())));
}

Expressions::Expression Expressions::Operators::operator-(Expressions::Variable & One, Expressions::Expression && Two)
{
	ON_DEBUG(std::cout << "Expressions::Operators::operator-(Expressions::Variable &, Expressions::Expression &&)" << std::endl);
	
	return Expressions::Expression(std::make_unique< Expressions::VariableTerm >(&One)) - std::move(Two.ExtractTerm());
}

Expressions::Expression Expressions::Operators::operator*(Expressions::Expression && One, Expressions::Expression && Two)
{
	ON_DEBUG(std::cout << "Expressions::Operators::operator*(Expressions::Expression &&, Expressions::Expression &&)" << std::endl);
	
	return Expressions::Expression(std::make_unique< Expressions::MultiplicationTerm >(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm())));
}

Expressions::Expression Expressions::Operators::operator/(Expressions::Expression && One, Expressions::Expression && Two)
{
	ON_DEBUG(std::cout << "Expressions::Operators::operator/(Expressions::Expression &&, Expressions::Expression &&)" << std::endl);
	
	return Expressions::Expression(std::make_unique< Expressions::DivisionTerm >(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm())));
}
