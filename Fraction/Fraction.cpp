//
//  Fraction.cpp
//  Fraction
//
//  Created by Анна Горячева on 21.04.2021.
//

#include "Fraction.h"
int Fraction::get_integer()const
{
    return integer;
}
int Fraction::get_numerator()const
{
    return numerator;
}
int Fraction::get_denominator()const
{
    return denominator;
}
void Fraction::set_integer(int integer)
{
    this->integer=integer;
}
void Fraction::set_numerator(int numerator)
{
    this->numerator=numerator;
}
void Fraction::set_denominator(int denominator)
{
    if(denominator==0)denominator=1;
    this->denominator=denominator;
}
// Constructors:
Fraction::Fraction()
{
    this->integer=0;
    this->numerator=0;
    this->denominator=1;
#ifdef DEBUG
    cout << "DefaultConstructor" << this << endl;
#endif //DEBUG
}
Fraction::Fraction(int integer)
{
    this->integer=integer;
    this->numerator=0;
    this->denominator=1;
#ifdef DEBUG
    cout << "SingleArgumentConstructor:" << this << endl;
#endif //DEBUG
}
Fraction::Fraction (double decimal)
{
    integer=decimal;
    double ost=decimal-integer;
    ost+=pow(10,-10);
    denominator=1;
    for(int i=0;i<9;i++)
    {
        ost*=10;
        denominator*=10;
    }
    
    numerator = ost;
    reduce();
}
Fraction::Fraction(int numerator, int denominator)
{
    this->integer=0;
    this->numerator=numerator;
    this->set_denominator(denominator);
#ifdef DEBUG
    cout << "Constructor:\t\t" << this << endl;
#endif //DEBUG
}

Fraction::Fraction(int integer, int numerator, int denominator)
{
this->integer=integer;
this->numerator=numerator;
this->set_denominator(denominator);
#ifdef DEBUG
cout << "Constructor:\t" << this << endl;
#endif //DEBUG
}
Fraction::Fraction(const Fraction& other)
{
    this->integer = other.integer;
    this->numerator=other.numerator;
    this->denominator=other.denominator;
#ifdef DEBUG
    cout << "CopyConstructor: \t" << this << endl;
#endif //DEBUG
}
Fraction::~Fraction()
{
#ifdef DEBUG
    cout << "Destructor:\t" << this << endl;
#endif //DEBUG
}
Fraction& Fraction::operator=(const Fraction& other)
{
    this->integer = other.integer;
    this->numerator=other.numerator;
    this->denominator=other.denominator;
#ifdef DEBUG
 //   cout << "CopyAssignment: \t" << this << endl;
#endif
    return *this;
}
Fraction& Fraction::operator++()  //Prefix increment
{
    integer++;
    return *this;
}
Fraction Fraction::operator++(int) // Postfix increment
{
    Fraction old= *this;
    integer++;
    return old;
}
Fraction& Fraction::operator--()  //Prefix increment
{
    integer--;
    return *this;
}
Fraction Fraction::operator--(int) // Postfix increment
{
    Fraction old= *this;
    integer--;
    return old;
}

// Type cast operators:
Fraction::operator int()const
{
    return integer;
}
Fraction::operator double()const
{
    return (integer+numerator/(double)denominator);
}

Fraction& Fraction::operator+=(const Fraction& other)
{
    return *this = *this+other;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
    return *this = *this*other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
    return *this = *this/other;
}
Fraction& Fraction::operator-=(const Fraction& other)
{
    return *this = *this-other;
}

Fraction& Fraction::to_proper()
{
//        Fraction copy=*this;
    integer+=numerator / denominator;
    numerator %= denominator;
    return *this;
//        copy.integer+=copy.numerator/copy.denominator;
//        copy.numerator%=copy.denominator;
//        return copy;
}
Fraction& Fraction::to_improper()
{
    numerator+= integer * denominator;
    integer=0;
    return *this;
//        Fraction copy = *this;
//        copy.numerator += copy.integer* copy.denominator;
//        copy.integer=0;
//        return copy;
}
Fraction Fraction::inverted()const
{
    Fraction inverted=*this;
    inverted.to_improper();
    swap(inverted.numerator,inverted.denominator);
    return inverted;
}

Fraction& Fraction::reduce()
{
    if(numerator==0)return  *this;;
    int more, less, rest;
    //определяем кто больше, числитель или знаменатель
    if(numerator>denominator)more=numerator, less=denominator;
    else less=numerator, more = denominator;
    // вычисляем наибольший общий делитель (НОД или   gcd)
    do
    {
        rest=more%less;
        more=less;
        less=rest;
    }while(rest);
    int GCD=more; // greatest common divisor
    //Сокращаем дробь
    numerator/=GCD;
    denominator/=GCD;
    return *this;
}
void Fraction::print()const
{
    cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
}
ostream& operator<<(ostream& os, const Fraction& obj)
{
    if(obj.get_integer())os << obj.get_integer();
    if(obj.get_numerator())
    {
        if(obj.get_integer())os << "(";
        os << obj.get_numerator() << "/"<< obj.get_denominator();
        if(obj.get_integer())os << ")";
    }
    else if (obj.get_integer()==0)os << 0;
    return os;
}
Fraction operator+(Fraction left,Fraction right)
{
    left.to_proper();
    right.to_proper();
    Fraction result;
    if(left.get_denominator()==right.get_denominator())
    {
result.set_numerator(left.get_numerator() + right.get_numerator());
result.set_denominator(right.get_denominator());
    }
    if(left.get_denominator()!=right.get_denominator())
    {
        result.set_numerator(left.get_numerator()*right.get_denominator() + right.get_numerator()*left.get_denominator());
        result.set_denominator(left.get_denominator()*right.get_denominator());
        if(result.get_numerator()>=result.get_denominator())
        {
            result.to_proper();
        }
    }
    result.reduce();
    return result;
}

Fraction operator-(Fraction left,Fraction right)
{
    left.to_proper();
    right.to_proper();
    Fraction result;
    if(left.get_denominator()==right.get_denominator())
    {
result.set_numerator(left.get_numerator() - right.get_numerator());
result.set_denominator(right.get_denominator());
#ifdef DEBUG
        cout << "Minus" << endl;
#endif
    }
    if(left.get_denominator()!=right.get_denominator())
    {
        result.set_numerator(left.get_numerator()*right.get_denominator() - right.get_numerator()*left.get_denominator());
        result.set_denominator(left.get_denominator()*right.get_denominator());
        if(result.get_numerator()>=result.get_denominator())
        {
            result.to_proper();
        }
    }
    result.reduce();
    return result;
}
Fraction operator*(Fraction left,Fraction right)
{
    left.to_improper();
    right.to_improper();
    Fraction result;
        result.set_numerator(left.get_numerator()*right.get_numerator());
        result.set_denominator(left.get_denominator()*right.get_denominator());
        if(result.get_numerator()>=result.get_denominator())
        {
            result.to_proper();
        }
    result.reduce();
    return result;
}
Fraction operator/(Fraction left,Fraction right)
{
//    left.to_improper();
//    right.to_improper();
//    Fraction result;
//        result.set_numerator(left.get_numerator()*right.get_denominator());
//        result.set_denominator(left.get_denominator()*right.get_numerator());
//        if(result.get_numerator()>=result.get_denominator())
//        {
//            result.to_proper();
//        }
    return left*right.inverted();
}
// Сравнение
void bringing_to_common (Fraction& left,Fraction& right)
{
    left.to_improper();
    right.to_improper();
    left.set_numerator(left.get_numerator()*right.get_denominator());
    right.set_numerator(right.get_numerator()*left.get_denominator());
    left.set_denominator(left.get_denominator()*right.get_denominator());
    right.set_denominator(left.get_denominator());
}
bool operator==(Fraction left, Fraction right)
{
    bringing_to_common(left, right);
    return (left.get_numerator()==right.get_numerator());
}
bool operator!=(const Fraction& left,const Fraction& right)
{
    return !(left == right);
}
bool operator<=(Fraction left, Fraction right)
{
    bringing_to_common(left, right);
    return (left.get_numerator()<=right.get_numerator());
}
bool operator>=(Fraction left, Fraction right)
{
    bringing_to_common(left, right);
    return (left.get_numerator()>=right.get_numerator());
}
bool operator<(Fraction left, Fraction right)
{
    
    bringing_to_common(left, right);
    return (left.get_numerator()<right.get_numerator());
}
bool operator>(Fraction left, Fraction right)
{
    bringing_to_common(left, right);
    //Fraction bring_to_common();
    return (left.get_numerator()>right.get_numerator());
}

