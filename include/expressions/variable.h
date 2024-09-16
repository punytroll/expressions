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

#ifndef EXPRESSIONS_VARIABLE_H
#define EXPRESSIONS_VARIABLE_H

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
