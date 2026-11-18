/**
 * expressions
 * Copyright (c) 2017-2026 Hagen Möbius
 * SPDX-License-Identifier: MIT
**/

#include <cassert>
#include <cmath>
#include <iostream>

#include <expressions/expressions.h>

using namespace Expressions::Operators;

///////////////////////////////////////////////////////////////////////////////////////////////////
// The following is the "widget" library, implemented using the "expression" library.            //
///////////////////////////////////////////////////////////////////////////////////////////////////

class Dimension : public Expressions::Variable
{
public:
    Dimension(void)
    {
    }
    
    void operator=(Expressions::Expression && Expression)
    {
        std::cout << "void Dimension::operator=(Expressions::Expression &&)\n";
        SetExpression(std::move(Expression));
    }
protected:
    virtual void InvalidateValue(void) override
    {
        std::cout << "Dimension::InvalidateValue(void)\n";
        Expressions::Variable::InvalidateValue();
        std::cout << "    new dimension: " << GetValue() << '\n';
    }
};

class Widget
{
public:
    friend Expressions::Expression height(std::shared_ptr<Widget> const & Widget);
    friend Expressions::Expression left(std::shared_ptr<Widget> const & Widget);
    friend Expressions::Expression top(std::shared_ptr<Widget> const & Widget);
    friend Expressions::Expression width(std::shared_ptr<Widget> const & Widget);
public:
    Widget(void)
    {
        m_Height = 0.0_c;
        m_Left = 0.0_c;
        m_Top = 0.0_c;
        m_Width = 0.0_c;
    }
    
    float GetHeight(void)
    {
        std::cout << "Widget::GetHeight()\n";
        
        return m_Height.GetValue();
    }
    
    float GetLeft(void)
    {
        std::cout << "Widget::GetLeft()\n";
        
        return m_Left.GetValue();
    }
    
    float GetTop(void)
    {
        std::cout << "Widget::GetTop()\n";
        
        return m_Top.GetValue();
    }
    
    float GetWidth(void)
    {
        std::cout << "Widget::GetWidth()\n";
        
        return m_Width.GetValue();
    }
    
    void SetHeight(Expressions::Expression && Height)
    {
        std::cout << "Widget::SetHeight(Expressions::Expression &&)\n";
        m_Height = std::move(Height);
    }
    
    void SetLeft(Expressions::Expression && Left)
    {
        std::cout << "Widget::SetLeft(Expressions::Expression &&)\n";
        m_Left = std::move(Left);
    }
    
    void SetTop(Expressions::Expression && Top)
    {
        std::cout << "Widget::SetTop(Expressions::Expression &&)\n";
        m_Top = std::move(Top);
    }
    
    void SetWidth(Expressions::Expression && Width)
    {
        std::cout << "Widget::SetWidth(Expressions::Expression &&)\n";
        m_Width = std::move(Width);
    }
private:
    Dimension m_Height;
    Dimension m_Left;
    Dimension m_Top;
    Dimension m_Width;
};

Expressions::Expression height(std::shared_ptr<Widget> const & Widget)
{
    std::cout << "Expressions::Expression height(std::shared_ptr<Widget> const &)\n";
    
    return Expressions::Expression{Widget->m_Height};
}

Expressions::Expression left(std::shared_ptr<Widget> const & Widget)
{
    std::cout << "Expressions::Expression left(std::shared_ptr<Widget> const &)\n";
    
    return Expressions::Expression{Widget->m_Left};
}

Expressions::Expression top(std::shared_ptr<Widget> const & Widget)
{
    std::cout << "Expressions::Expression top(std::shared_ptr<Widget> const &)\n";
    
    return Expressions::Expression{Widget->m_Top};
}

Expressions::Expression width(std::shared_ptr<Widget> const & Widget)
{
    std::cout << "Expressions::Expression width(std::shared_ptr<Widget> const &)\n";
    
    return Expressions::Expression{Widget->m_Width};
}

int main()
{
    auto TestNumber{1};
    
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Expression Expression;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(std::isnan(Expression.GetValue()) == true);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto Expression{20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Expression.GetValue() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Expression Expression;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        Expression = constant(20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Expression.GetValue() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto ExpressionOne{56.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto ExpressionTwo{std::move(ExpressionOne)};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(ExpressionTwo.GetValue() == 56.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Expression ExpressionOne;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        {
            auto ExpressionTwo{76.0_c};
            
            std::cout << "------------------------ " << TestNumber << " ------------------------\n";
            ExpressionOne = std::move(ExpressionTwo);
            std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        }
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(ExpressionOne.GetValue() == 76.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{56.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto Negation{-std::move(One)};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Negation.GetValue() == -56.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto Two{13.5_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto Addition{std::move(One) + std::move(Two)};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Addition.GetValue() == 33.5f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto Addition{20.0_c + 13.5_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Addition.GetValue() == 33.5f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    // Variable tests
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One = 23.0_c;
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One.GetValue() == 23.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    // Variable tests
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One{58.5_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One = Expressions::Expression();
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One = constant(23.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One.GetValue() == 23.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One{40.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        Expressions::Expression Expression{One};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Expression.GetValue() == 40.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One{34.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto Negative{-One};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Negative.GetValue() == -34.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One{76.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One.Reset();
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(std::isnan(One.GetValue()) == true);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One{20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        Expressions::Variable Two{80.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto Addition{One + Two};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Addition.GetValue() == 100.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One{20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        Expressions::Variable Two{80.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto Addition{One + Two};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One = 50.0_c;
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Addition.GetValue() == 130.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable Width{300.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto WidthOne{(Width - 3.0_c * 10.0_c) / 2.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(WidthOne.GetValue() == 135.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable Addition{20.0_c + 55.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Addition.GetValue() == 75.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(std::isnan(One.GetValue()) == true);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto Result{One - 20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(std::isnan(Result.GetValue()) == true);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto Result{One - 20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One = 40.0_c * 2.0_c;
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Result.GetValue() == 60.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        Expressions::Variable Two;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        Expressions::Variable Three;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        Two = One;
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        Three = Two;
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One.SetExpression(40.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Three.GetValue() == 40.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetHeight() == 0.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetLeft() == 0.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetTop() == 0.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetWidth() == 0.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetHeight(30.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetHeight() == 30.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetLeft(40.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetLeft() == 40.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetHeight(left(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetLeft(30.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetHeight(left(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetLeft() == 30.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetHeight() == 30.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetHeight(left(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetLeft(30.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetLeft() == 30.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetHeight() == 30.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetHeight(left(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetLeft(130.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetLeft() == 130.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetHeight() == 130.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetLeft(67.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetLeft() == 67.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetHeight() == 67.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        {
            auto Two{std::make_shared< Widget >()};
            
            std::cout << "------------------------ " << TestNumber << " ------------------------\n";
            One->SetLeft(top(Two));
            std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        }
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(std::isnan(One->GetLeft()) == true);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto Two{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetLeft(top(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        Two->SetWidth(top(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetTop(20.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetTop() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetLeft() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Two->GetWidth() == 20.0f);
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        
        auto Two{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetLeft(top(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        Two->SetWidth(left(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        One->SetTop(20.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetTop() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(One->GetLeft() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------\n";
        assert(Two->GetWidth() == 20.0f);
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>\n";
    {
        auto Variable = Expressions::Variable{};
        auto Expression = 44.0_c * Variable;
        
        Variable.SetExpression(1.5_c);
        assert(Expression.GetValue() == 66.0f);
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n\n";
    
    return 0;
}
