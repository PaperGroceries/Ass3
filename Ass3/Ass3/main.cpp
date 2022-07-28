//
//  main.cpp
//  Ass3
//
//  Created by Aim Kim on 2022-07-27.
//

#include <iostream>

using namespace std;

class Polynomial
{
    double *arr;
    int del_size;
public:
    Polynomial();
    Polynomial(int size );
    Polynomial(double, double);
//    Polynomial(double, double, double );
//    Polynomial(double, double, double, double );
    Polynomial(const Polynomial&);
    void operator+(const Polynomial &);
    void operator=(const Polynomial &);
    void set(int exponent, double coefficient);
    void get();
    ~Polynomial();
};
Polynomial::Polynomial()
{
    arr = new double[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 1;
}
Polynomial :: Polynomial(int exponent)
{
    del_size = exponent + 1;
    arr = new double[exponent + 1];
    for (int i = 0; i < (exponent + 1); i++)
    {
        arr[i] = 0;
    }
}
Polynomial::Polynomial(const Polynomial&y)
{
    //create dynamic variable
    //make a deep copy done!
    double *arr = new double[10];
    *arr = *(y.arr);
}
void Polynomial::operator+(const Polynomial & RightSide)
{
    
}
void Polynomial::operator=(const Polynomial & RightSide)
{
    
}
Polynomial::~Polynomial()
{
//    for (int i = 0; i < del_size; i++)
//    {
//        delete arr[i];
//    }
    delete []arr;
}
void Polynomial::set(int exponent, double coefficient)
{
    arr[exponent] = coefficient;
}
void Polynomial::get()
{
    cout << arr[0];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Polynomial a(4);
    a.set(1,2);
    a.set(0,1);
    a.set(2,2);
    a.set(3,3);
    a.set(4,5);
    a.get();
    return 0;
}
