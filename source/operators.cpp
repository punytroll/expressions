/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
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

Expressions::Expression Expressions::Operators::operator""_c(long double Value)
{
    LOG_TRACE(std::cout << "Expressions::Operators::operator\"\" _c(long double)" << std::endl);
    
    return Expressions::Expression(std::make_unique< Expressions::ConstantTerm >(Value));
}

Expressions::Expression Expressions::Operators::constant(double Value)
{
    LOG_TRACE(std::cout << "Expressions::Operators::constant(double)" << std::endl);
    
    return Expressions::Expression(std::make_unique< Expressions::ConstantTerm >(Value));
}

Expressions::Expression Expressions::Operators::operator-(Expressions::Expression && One)
{
    LOG_TRACE(std::cout << "Expressions::Operators::operator-(Expressions::Expression &&)" << std::endl);
    
    return Expressions::Expression(std::make_unique< Expressions::NegationTerm >(std::move(One.ExtractTerm())));
}

Expressions::Expression Expressions::Operators::operator-(Expressions::Variable & Variable)
{
    LOG_TRACE(std::cout << "Expressions::Operators::operator-(Expressions::Variable &)" << std::endl);
    
    return -Expressions::Expression(std::make_unique< Expressions::VariableTerm >(&Variable));
}

Expressions::Expression Expressions::Operators::operator+(Expressions::Expression && One, Expressions::Expression && Two)
{
    LOG_TRACE(std::cout << "Expressions::Operators::operator+(Expressions::Expression &&, Expressions::Expression &&)" << std::endl);
    
    return Expressions::Expression(std::make_unique< Expressions::AdditionTerm >(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm())));
}

Expressions::Expression Expressions::Operators::operator+(Expressions::Variable & One, Expressions::Expression && Two)
{
    LOG_TRACE(std::cout << "Expressions::Operators::operator+(Expressions::Variable &, Expressions::Expression &&)" << std::endl);
    
    return Expressions::Expression(std::make_unique< Expressions::VariableTerm >(&One)) + std::move(Two.ExtractTerm());
}

Expressions::Expression Expressions::Operators::operator+(Expressions::Variable & One, Expressions::Variable & Two)
{
    LOG_TRACE(std::cout << "Expressions::Operators::operator+(Expressions::Variable &, Expressions::Variable &)" << std::endl);
    
    return Expressions::Expression(std::make_unique< Expressions::VariableTerm >(&One)) + Expressions::Expression(std::make_unique< Expressions::VariableTerm >(&Two));
}

Expressions::Expression Expressions::Operators::operator-(Expressions::Expression && One, Expressions::Expression && Two)
{
    LOG_TRACE(std::cout << "Expressions::Operators::operator+(Expressions::Expression &&, Expressions::Expression &&)" << std::endl);
    
    return Expressions::Expression(std::make_unique< Expressions::SubtractionTerm >(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm())));
}

Expressions::Expression Expressions::Operators::operator-(Expressions::Variable & One, Expressions::Expression && Two)
{
    LOG_TRACE(std::cout << "Expressions::Operators::operator-(Expressions::Variable &, Expressions::Expression &&)" << std::endl);
    
    return Expressions::Expression(std::make_unique< Expressions::VariableTerm >(&One)) - std::move(Two.ExtractTerm());
}

Expressions::Expression Expressions::Operators::operator*(Expressions::Expression && One, Expressions::Expression && Two)
{
    LOG_TRACE(std::cout << "Expressions::Operators::operator*(Expressions::Expression &&, Expressions::Expression &&)" << std::endl);
    
    return Expressions::Expression(std::make_unique< Expressions::MultiplicationTerm >(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm())));
}

Expressions::Expression Expressions::Operators::operator/(Expressions::Expression && One, Expressions::Expression && Two)
{
    LOG_TRACE(std::cout << "Expressions::Operators::operator/(Expressions::Expression &&, Expressions::Expression &&)" << std::endl);
    
    return Expressions::Expression(std::make_unique< Expressions::DivisionTerm >(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm())));
}
