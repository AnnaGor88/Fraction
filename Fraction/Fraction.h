//
//  Fraction.h
//  Fraction
//
//  Created by Анна Горячева on 21.04.2021.
//

#ifndef Fraction_h
#define Fraction_h
#define DELIMETER "\n------------------------------\n"
#undef DEBUG

#define tab "\t"

#include <iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left,Fraction right);
Fraction operator/(Fraction left,Fraction right);
Fraction operator+(Fraction left,Fraction right);
Fraction operator-(Fraction left,Fraction right);

#define DEBUG

class Fraction
{
    int numerator; // числитель
    int denominator; //  знаменатель
    int integer; //целая часть
public:
    int get_integer()const;
    int get_numerator()const;
    int get_denominator()const;
    void set_integer(int integer);
    void set_numerator(int numerator);
    void set_denominator(int denominator);
// Constructors:
    Fraction();
    explicit Fraction(int integer);
    Fraction (double decimal);
    Fraction(int numerator, int denominator);
    
    Fraction(int integer, int numerator, int denominator);
    Fraction(const Fraction& other);
    ~Fraction();
    Fraction& operator=(const Fraction& other);
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);
    
    // Type cast operators:
    operator int()const;
    explicit operator double()const;
    
    Fraction& operator+=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    
    Fraction& to_proper();
    Fraction& to_improper();
    Fraction inverted()const;
    
    Fraction& reduce();
    void print()const;
};
void bringing_to_common (Fraction& left,Fraction& right);


#endif /* Fraction_h */
