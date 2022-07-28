//
//  main.cpp
//  Ass3
//
//  Created by Aim Kim on 2022-07-27.
//

#include <iostream>

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
    void Pol_set(int place, double coefficient);
    ~Polynomial();
};
Polynomial::Polynomial()
{
    double *arr = new double[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 1;
}
Polynomial :: Polynomial(int size)
{
    del_size = size;
    double *arr = new double[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}
Polynomial::Polynomial(const Polynomial&y)
{
    //create dynamic variable
    //make a deep copy
    
}
void Polynomial::operator+(const Polynomial & RightSide)
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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Polynomial a(4);
    return 0;
}
