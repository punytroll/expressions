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
        std::cout << "void Dimension::operator=(Expressions::Expression &&)" << std::endl;
        SetExpression(std::move(Expression));
    }
protected:
    virtual void InvalidateValue(void) override
    {
        std::cout << "Dimension::InvalidateValue(void)" << std::endl;
        Expressions::Variable::InvalidateValue();
        std::cout << "    new dimension: " << GetValue() << std::endl;
    }
};

class Widget
{
public:
    friend Expressions::Expression height(std::shared_ptr< Widget > Widget);
    friend Expressions::Expression left(std::shared_ptr< Widget > Widget);
    friend Expressions::Expression top(std::shared_ptr< Widget > Widget);
    friend Expressions::Expression width(std::shared_ptr< Widget > Widget);
public:
    Widget(void)
    {
        _Height = 0.0_c;
        _Left = 0.0_c;
        _Top = 0.0_c;
        _Width = 0.0_c;
    }
    
    float GetHeight(void)
    {
        std::cout << "Widget::GetHeight()" << std::endl;
        return _Height.GetValue();
    }
    
    float GetLeft(void)
    {
        std::cout << "Widget::GetLeft()" << std::endl;
        return _Left.GetValue();
    }
    
    float GetTop(void)
    {
        std::cout << "Widget::GetTop()" << std::endl;
        return _Top.GetValue();
    }
    
    float GetWidth(void)
    {
        std::cout << "Widget::GetWidth()" << std::endl;
        return _Width.GetValue();
    }
    
    void SetHeight(Expressions::Expression && Height)
    {
        std::cout << "Widget::SetHeight(Expressions::Expression &&)" << std::endl;
        _Height = std::move(Height);
    }
    
    void SetLeft(Expressions::Expression && Left)
    {
        std::cout << "Widget::SetLeft(Expressions::Expression &&)" << std::endl;
        _Left = std::move(Left);
    }
    
    void SetTop(Expressions::Expression && Top)
    {
        std::cout << "Widget::SetTop(Expressions::Expression &&)" << std::endl;
        _Top = std::move(Top);
    }
    
    void SetWidth(Expressions::Expression && Width)
    {
        std::cout << "Widget::SetWidth(Expressions::Expression &&)" << std::endl;
        _Width = std::move(Width);
    }
private:
    Dimension _Height;
    Dimension _Left;
    Dimension _Top;
    Dimension _Width;
};

Expressions::Expression height(std::shared_ptr< Widget > Widget)
{
    std::cout << "Expressions::Expression height(std::shared_ptr< Widget >)" << std::endl;
    
    return Widget->_Height;
}

Expressions::Expression left(std::shared_ptr< Widget > Widget)
{
    std::cout << "Expressions::Expression left(std::shared_ptr< Widget >)" << std::endl;
    
    return Widget->_Left;
}

Expressions::Expression top(std::shared_ptr< Widget > Widget)
{
    std::cout << "Expressions::Expression top(std::shared_ptr< Widget >)" << std::endl;
    
    return Widget->_Top;
}

Expressions::Expression width(std::shared_ptr< Widget > Widget)
{
    std::cout << "Expressions::Expression width(std::shared_ptr< Widget >)" << std::endl;
    
    return Widget->_Width;
}

int main()
{
    auto TestNumber{1};
    
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Expression Expression;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(std::isnan(Expression.GetValue()) == true);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto Expression{20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Expression.GetValue() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Expression Expression;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        Expression = constant(20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Expression.GetValue() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto ExpressionOne{56.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto ExpressionTwo{std::move(ExpressionOne)};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(ExpressionTwo.GetValue() == 56.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Expression ExpressionOne;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        {
            auto ExpressionTwo{76.0_c};
            
            std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
            ExpressionOne = std::move(ExpressionTwo);
            std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        }
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(ExpressionOne.GetValue() == 76.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{56.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto Negation{-std::move(One)};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Negation.GetValue() == -56.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto Two{13.5_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto Addition{std::move(One) + std::move(Two)};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Addition.GetValue() == 33.5f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto Addition{20.0_c + 13.5_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Addition.GetValue() == 33.5f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    // Variable tests
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One = 23.0_c;
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One.GetValue() == 23.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    // Variable tests
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One{58.5_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One = Expressions::Expression();
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One = constant(23.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One.GetValue() == 23.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One{40.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        Expressions::Expression Expression{One};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Expression.GetValue() == 40.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One{34.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto Negative{-One};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Negative.GetValue() == -34.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One{76.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One.Reset();
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(std::isnan(One.GetValue()) == true);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One{20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        Expressions::Variable Two{80.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto Addition{One + Two};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Addition.GetValue() == 100.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One{20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        Expressions::Variable Two{80.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto Addition{One + Two};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One = 50.0_c;
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Addition.GetValue() == 130.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable Width{300.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto WidthOne{(Width - 3.0_c * 10.0_c) / 2.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(WidthOne.GetValue() == 135.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable Addition{20.0_c + 55.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Addition.GetValue() == 75.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(std::isnan(One.GetValue()) == true);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto Result{One - 20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(std::isnan(Result.GetValue()) == true);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto Result{One - 20.0_c};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One = 40.0_c * 2.0_c;
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Result.GetValue() == 60.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        Expressions::Variable One;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        Expressions::Variable Two;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        Expressions::Variable Three;
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        Two = One;
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        Three = Two;
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One.SetExpression(40.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Three.GetValue() == 40.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetHeight() == 0.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetLeft() == 0.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetTop() == 0.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetWidth() == 0.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetHeight(30.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetHeight() == 30.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetLeft(40.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetLeft() == 40.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetHeight(left(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetLeft(30.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetHeight(left(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetLeft() == 30.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetHeight() == 30.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetHeight(left(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetLeft(30.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetLeft() == 30.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetHeight() == 30.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetHeight(left(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetLeft(130.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetLeft() == 130.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetHeight() == 130.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetLeft(67.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetLeft() == 67.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetHeight() == 67.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        {
            auto Two{std::make_shared< Widget >()};
            
            std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
            One->SetLeft(top(Two));
            std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        }
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(std::isnan(One->GetLeft()) == true);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto Two{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetLeft(top(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        Two->SetWidth(top(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetTop(20.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetTop() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetLeft() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Two->GetWidth() == 20.0f);
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    TestNumber += 1;
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>> " << TestNumber << " >>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    {
        auto One{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        
        auto Two{std::make_shared< Widget >()};
        
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetLeft(top(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        Two->SetWidth(left(One));
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        One->SetTop(20.0_c);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetTop() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(One->GetLeft() == 20.0f);
        std::cout << "------------------------ " << TestNumber << " ------------------------" << std::endl;
        assert(Two->GetWidth() == 20.0f);
    }
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<< " << TestNumber << " <<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
    
    return 0;
}
