//
//  main.cpp
//  Fraction
//
//  Created by Анна Горячева on 30.03.2021.
//
#include <iostream>
using namespace std;
class Fraction;
Fraction operator*(Fraction left,Fraction right);
Fraction operator/(Fraction left,Fraction right);
Fraction operator+(Fraction left,Fraction right);
Fraction operator-(Fraction left,Fraction right);
class Fraction
{
    int numerator; // числитель
    int denominator; //  знаменатель
    int integer; //целая часть
public:
    int get_integer()const
    {
        return integer;
    }
    int get_numerator()const
    {
        return numerator;
    }
    int get_denominator()const
    {
        return denominator;
    }
    void set_integer(int integer)
    {
        this->integer=integer;
    }
    void set_numerator(int numerator)
    {
        this->numerator=numerator;
    }
    void set_denominator(int denominator)
    {
        if(denominator==0)denominator=1;
        this->denominator=denominator;
    }
// Constructors:
    Fraction()
    {
        this->integer=0;
        this->numerator=0;
        this->denominator=1;
        cout << "DefaultConstructor" << this << endl;
    }
    Fraction(int integer)
    {
        this->integer=integer;
        this->numerator=0;
        this->denominator=1;
        cout << "SingleArgumentConstructor:" << this << endl;
    }
    Fraction(int numerator, int denominator)
    {
        this->integer=0;
        this->numerator=numerator;
        this->set_denominator(denominator);
        cout << "Constructor:\t\t" << this << endl;
    }
    
Fraction(int integer, int numerator, int denominator)
{
    this->integer=integer;
    this->numerator=numerator;
    this->set_denominator(denominator);
    cout << "Constructor:\t" << this << endl;
}
    Fraction(const Fraction& other)
    {
        this->integer = other.integer;
        this->numerator=other.numerator;
        this->denominator=other.denominator;
        cout << "CopyConstructor: \t" << this << endl;
    }
    ~Fraction()
    {
        cout << "Destructor:\t" << this << endl;
    }
    Fraction& operator=(const Fraction& other)
    {
        this->integer = other.integer;
        this->numerator=other.numerator;
        this->denominator=other.denominator;
        cout << "CopyAssignment: \t" << this << endl;
        return *this;
    }
    Fraction& operator++()  //Prefix increment
    {
        this->numerator++;
        this->denominator++;
        return *this;
    }
    Fraction operator++(int) // Postfix increment
    {
        Fraction old= *this;
        this->numerator++;
        this->denominator++;
        return old;
    }
    Fraction& operator--()  //Prefix increment
    {
        this->numerator--;
        this->denominator--;
        return *this;
    }
    Fraction operator--(int) // Postfix increment
    {
        Fraction old= *this;
        this->numerator--;
        this->denominator--;
        return old;
    }
    Fraction& operator+=(const Fraction& other)
    {
        return *this = *this+other;
    }
    Fraction& operator*=(const Fraction& other)
    {
        return *this = *this*other;
    }
    Fraction& operator/=(const Fraction& other)
    {
        return *this = *this/other;
    }
    Fraction& operator-=(const Fraction& other)
    {
        return *this = *this-other;
    }
    
//    Fraction operator*(const Fraction& other)const
//    {
//        Fraction left = *this;
//        Fraction right = other;
//        left.to_improper();
//        right.to_improper();
//        return Fraction
//        (
//            left.numerator*right.numerator,
//            left.denominator*right.denominator
//        );
//    }
    Fraction& to_proper()
    {
//        Fraction copy=*this;
        integer+=numerator / denominator;
        numerator %= denominator;
        return *this;
//        copy.integer+=copy.numerator/copy.denominator;
//        copy.numerator%=copy.denominator;
//        return copy;
    }
    Fraction& to_improper()
    {
        numerator+= integer * denominator;
        integer=0;
        return *this;
//        Fraction copy = *this;
//        copy.numerator += copy.integer* copy.denominator;
//        copy.integer=0;
//        return copy;
    }
    Fraction NOD()
    {
        to_proper();
        while(numerator && denominator){
            if(numerator>=denominator){
                numerator%=denominator;
            }
            else
                denominator%=numerator;
        }
        return numerator | denominator;
    }
    void reduce()
    {
        numerator/NOD();
        denominator/NOD();
    }
    void print()const
    {
        cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
    }
};
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
        cout << "Minus" << endl;
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
    return result;
}
Fraction operator/(Fraction left,Fraction right)
{
    left.to_improper();
    right.to_improper();
    Fraction result;
        result.set_numerator(left.get_numerator()*right.get_denominator());
        result.set_denominator(left.get_denominator()*right.get_numerator());
        if(result.get_numerator()>=result.get_denominator())
        {
            result.to_proper();
        }
    return result;
}
// Сравнение
void bringing_to_common (Fraction& left,Fraction& right)
{
    //newdenominator=left.get_denominator()*right.get_denominator();
    left.set_numerator(left.get_numerator()*right.get_denominator());
    right.set_numerator(right.get_numerator()*left.get_denominator());
    left.set_denominator(left.get_denominator()*right.get_denominator());
    right.set_denominator(left.get_denominator());
    //return newdenominator;
}
bool operator==(Fraction left, Fraction right)
{
    bringing_to_common(left, right);
    return (left.get_numerator()==right.get_numerator());
}
bool operator!=(Fraction left, Fraction right)
{
    bringing_to_common(left, right);
    return !(left==right);
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

//#define CONSTRUCTORS_CHECK
#define delimeter "\n-----------------------------------------\n"

int main()
{
    setlocale (LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
    Fraction A; // Default constructor
    A.print();
    cout << A << endl;
    double b=5;
    Fraction B=5;
    B.print();
    cout << B << endl;
    Fraction C(0,1,2);
    C.print();
    cout << C << endl;
    Fraction D(3,4,5);
    D.print();
    cout << D << endl;
#endif
//    Fraction A(11,4);
//    cout << A << endl;
//    cout << A.to_improper() << "=" << A.to_proper() << endl;
////    A.to_proper();
////    cout << A.to_proper() << endl;
//    cout << A.to_proper() << "=" << A.to_improper() << endl;
//    Fraction B(5,6,7);
//    cout << delimeter << endl;
//    Fraction C = A +B;
//    cout << delimeter << endl;
//    cout << C << endl;
//    cout << delimeter << endl;
//    C=A/B;
//    cout << delimeter << endl;
//    cout << C << endl;
//    cout << delimeter << endl;
//    double a=2;
//    double b=3;
//    a*=3;
    Fraction A(1,12,4);
    Fraction B(5,6,7);
    A*=B;
    cout << A << endl;
    if(A==A)
        cout << "Equal" << endl;
    else
        cout << "Different" << endl;
        return 0;
}
