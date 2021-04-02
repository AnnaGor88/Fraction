//
//  main.cpp
//  Fraction
//
//  Created by Анна Горячева on 30.03.2021.
//
#include <iostream>
using namespace std;

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
    Fraction operator=(const Fraction& other)
    {
        this->integer = other.integer;
        this->numerator=other.numerator;
        this->denominator=other.denominator;
        cout << "CopyAssignment: \t" << this << endl;
        return *this;
    }
    Fraction operator+=(const Fraction& other)
    {
        this->integer += other.integer;
        this->numerator += other.numerator;
        this->denominator += other.denominator;
        cout << "Operator+=\t" << this << endl;
        return *this;
    }
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

//#define CONSTRUCTORS_CHECK

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
    Fraction A(11,4);
    cout << A << endl;
    cout << A.to_improper() << "=" << A.to_proper() << endl;
//    A.to_proper();
//    cout << A.to_proper() << endl;
    cout << A.to_proper() << "=" << A.to_improper() << endl;
    return 0;
}
