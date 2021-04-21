//
//  main.cpp
//  Fraction
//
//  Created by Анна Горячева on 30.03.2021.
//
#include "Fraction.h"
#define DELIMETER "\n------------------------------\n"
#undef DEBUG

#define tab "\t"

#include <iostream>
#include "Fraction.h"
using namespace std;

//#define CONSTRUCTORS_CHECK
#define delimeter "\n-----------------------------------------\n"

//#define COMPAUND_ASSIGNMENTS
//#define INCREMENT_CHECK
//#define COMPARISON_OPERATORS
#define TYPE_CONVERSIONS
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
#ifdef COMPAUND_ASSIGNMENTS
    Fraction A(11,4);
    Fraction B(5,6,7);
    cout << DELIMETER << endl;
    cout << A << endl;
    cout << B << endl;
    cout << DELIMETER << endl;
    A*=B;
    cout << A << endl;
    if(A==A)
        cout << "Equal" << endl;
    else
        cout << "Different" << endl;
    cout << DELIMETER << endl;
    A/=B;
    cout << A << endl;
    cout << DELIMETER << endl;
    cout << A-A<<endl;
#endif
#ifdef INCREMENT_CHECK
    for(double i= .3; i<10; i++)
    cout << i << tab;
    cout << endl;
    for(Fraction i(3,4);i.get_integer()<10;i++)
    cout << i << tab;
    cout << endl;
#endif
#ifdef COMPARISON_OPERATORS
    Fraction A(1,2);
    Fraction B(5,11);
    cout << A << endl;
    cout << B << endl;
//    if (A==B)
//        cout << "Дроби равны!" << endl;
//    else
//        cout << "Дроби разные!" << endl;
    cout << DELIMETER << endl;
    cout << (A==B) << endl;
    cout << DELIMETER << endl;
//    cout <<(Fraction(1,2)!= Fraction(5,11)) << endl;
    cout << (A!=B) << endl;
    cout << DELIMETER << endl;
    cout << A << endl;
    cout << B << endl;
#endif
#ifdef TYPE_CONVERSIONS
//    int a=2; // No conversion
//    double b=3; // From less to more (от меньшего к большему)
//    int c=5.0; // От большего к меньшему без потери данных
//    int d=5.2; //От большего к меньшему с потерей данных
//    char e = 43; //От большего к меньшему без потери данных
//    char f = 555; //От большего к меньшему с потерей данных truncation(урезание,усечение)
//    cout << f << endl;
    Fraction A(5); // explicit constructor можно вызвать только так и никак иначе
    cout << A << endl;
    A=(Fraction)8; // From int to Fraction (Single Argument Constructor)
    cout << A << endl;
    Fraction B(3,4,5);
    double b=B;
    cout << b << endl;
    Fraction C = 2.55;
    cout << C << endl;
    cout << DELIMETER << endl;
    cout << C << endl;
    cout << DELIMETER << endl;
#endif
    
    return 0;
}
