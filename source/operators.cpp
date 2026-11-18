/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

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

auto Expressions::Operators::operator""_c(long double Value) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::operator\"\" _c(long double) -> Expressions::Expression");
    
    return Expressions::Expression{std::make_unique<Expressions::ConstantTerm>(Value)};
}

auto Expressions::Operators::constant(float Value) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::constant(float) -> Expressions::Expression");
    
    return Expressions::Expression{std::make_unique<Expressions::ConstantTerm>(Value)};
}

auto Expressions::Operators::operator-(Expressions::Expression && One) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::operator-(Expressions::Expression &&) -> Expressions::Expression");
    
    return Expressions::Expression{std::make_unique<Expressions::NegationTerm>(std::move(One.ExtractTerm()))};
}

auto Expressions::Operators::operator-(Expressions::Variable & Variable) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::operator-(Expressions::Variable &) -> Expressions::Expression");
    
    return -Expressions::Expression{std::make_unique<Expressions::VariableTerm>(&Variable)};
}

auto Expressions::Operators::operator+(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::operator+(Expressions::Expression &&, Expressions::Expression &&) -> Expressions::Expression");
    
    return Expressions::Expression{std::make_unique<Expressions::AdditionTerm>(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm()))};
}

auto Expressions::Operators::operator+(Expressions::Variable & One, Expressions::Expression && Two) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::operator+(Expressions::Variable &, Expressions::Expression &&) -> Expressions::Expression");
    
    return Expressions::Expression{std::make_unique<Expressions::VariableTerm>(&One)} + Expressions::Expression{std::move(Two.ExtractTerm())};
}

auto Expressions::Operators::operator+(Expressions::Variable & One, Expressions::Variable & Two) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::operator+(Expressions::Variable &, Expressions::Variable &) -> Expressions::Expression");
    
    return Expressions::Expression{std::make_unique<Expressions::VariableTerm>(&One)} + Expressions::Expression{std::make_unique< Expressions::VariableTerm >(&Two)};
}

auto Expressions::Operators::operator-(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::operator+(Expressions::Expression &&, Expressions::Expression &&) -> Expressions::Expression");
    
    return Expressions::Expression{std::make_unique<Expressions::SubtractionTerm>(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm()))};
}

auto Expressions::Operators::operator-(Expressions::Variable & One, Expressions::Expression && Two) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::operator-(Expressions::Variable &, Expressions::Expression &&) -> Expressions::Expression");
    
    return Expressions::Expression{std::make_unique<Expressions::VariableTerm>(&One)} - Expressions::Expression{std::move(Two.ExtractTerm())};
}

auto Expressions::Operators::operator*(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::operator*(Expressions::Expression &&, Expressions::Expression &&) -> Expressions::Expression");
    
    return Expressions::Expression{std::make_unique<Expressions::MultiplicationTerm>(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm()))};
}

auto Expressions::Operators::operator*(Expressions::Expression && One, Expressions::Variable & Two) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::operator*(Expressions::Expression &&, Expressions::Variable &) -> Expressions::Expression");
    
    return Expressions::Expression{std::make_unique<Expressions::MultiplicationTerm>(std::move(One.ExtractTerm()), std::make_unique<Expressions::VariableTerm>(std::addressof(Two)))};
}

auto Expressions::Operators::operator/(Expressions::Expression && One, Expressions::Expression && Two) -> Expressions::Expression
{
    LOG_TRACE("auto Expressions::Operators::operator/(Expressions::Expression &&, Expressions::Expression &&) -> Expressions::Expression");
    
    return Expressions::Expression{std::make_unique<Expressions::DivisionTerm>(std::move(One.ExtractTerm()), std::move(Two.ExtractTerm()))};
}
