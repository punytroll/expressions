/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
 **/

#ifndef EXPRESSIONS__INCLUDE__EXPRESSIONS__TERM_H
#define EXPRESSIONS__INCLUDE__EXPRESSIONS__TERM_H

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
        
        ~Term() override;
        Term(const Expressions::Term & Term) = delete;
        Term(Expressions::Term && Term) = delete;
        auto operator=(Expressions::Term const & Term) -> Expressions::Term & = delete;
        auto operator=(Expressions::Term && Term) -> Expressions::Term & = delete;
        auto GetValue() -> float;
        virtual auto Calculate() -> float = 0;
        auto InvalidateValue() -> void override;
        auto SetParent(Expressions::TermParent * Parent) -> void;
    protected:
        Term();
        
    private:
        Expressions::TermParent * m_Parent = nullptr;
        std::optional<float> m_Value;
    }; 
}

#endif
