/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__INCLUDE__EXPRESSIONS__VARIABLE_H
#define EXPRESSIONS__INCLUDE__EXPRESSIONS__VARIABLE_H

#include <memory>
#include <unordered_set>

#include <expressions/term_parent.h>

namespace Expressions
{
    class Expression;
    class Term;
    class VariableTerm;
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    // As part of the "expression" library, a Variable contains an expression, that can be changed.  //
    // Other expressions can reference this variable and its value with a VariableTerm. These terms  //
    // are called dependent, because any change of the variable's value (by changing its expression) //
    // also changes the value of the VariableTerm. A list of back references to the dependent term   //
    // is kept, so that invalidations can be propagated appropriately.                               //
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    
    class Variable : public TermParent
    {
    public:
        friend class Expressions::VariableTerm;
    public:
        Variable(const Expressions::Variable & Variable) = delete;
        Variable(Expressions::Variable && Variable) = delete;
        Expressions::Variable & operator=(const Expressions::Variable & Variable) = delete;
        Expressions::Variable & operator=(Expressions::Variable && Variable) = delete;
    public:
        Variable(void);
        Variable(Expressions::Expression && Expression);
        ~Variable(void);
        float GetValue(void);
        virtual void InvalidateValue(void) override;
        void Reset(void);
        void SetExpression(Expressions::Expression && Expression);
        Expressions::Variable & operator=(Expressions::Variable & Variable);
        Expressions::Variable & operator=(Expressions::Expression && Expression);
    private:
        void _AddDependentTerm(Expressions::VariableTerm * DependentVariableTerm);
        void _RemoveDependentTerm(Expressions::VariableTerm * DependentVariableTerm);
        std::unordered_multiset< Expressions::VariableTerm * > _DependentVariableTerms;
        std::unique_ptr< Expressions::Term > _Term;
    };
}

#endif
