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
//    double *sum;
    
    int del_size;
public:
    Polynomial();
    Polynomial(int size );
    Polynomial(double, double);
//    Polynomial(double, double, double );
//    Polynomial(double, double, double, double );
    Polynomial(const Polynomial&);
    friend Polynomial operator+(const Polynomial &,const Polynomial &);
    friend Polynomial operator*(const Polynomial &,const Polynomial &);
    void operator=(const Polynomial &);
    void set(int exponent, double coefficient);
    void get();
    ~Polynomial();
};
Polynomial::Polynomial()
{
    arr = new double[10];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 1;
}
Polynomial :: Polynomial(int exponent)
{
    del_size = exponent + 1;
    arr = new double[exponent +1];
    for (int i = 0; i < (exponent + 1); i++)
    {
        arr[i] = 0;
    }
}
Polynomial::Polynomial(const Polynomial&y)
{
    //create dynamic variable
    //make a deep copy
    arr = new double[del_size];
//    *arr = *(y.arr);
    
    for (int i = 0; i < del_size; i++)
    {
        arr[i] = y.arr[i];
    }
    
}
 Polynomial operator+(const Polynomial & LeftSide,const Polynomial & RightSide)
{
    Polynomial sum;
   // int n_coefficient;
    if(LeftSide.del_size >= RightSide.del_size)
    {
        sum.del_size = LeftSide.del_size;
    }
//    sum = new double[10];
    else if (RightSide.del_size > LeftSide.del_size)
    {
        sum.del_size = RightSide.del_size;
    }
     for (int i = 0; i < sum.del_size ; i++)
     {
         sum.arr[i] = LeftSide.arr[i] + RightSide.arr[i];
     }
     
//    for(int i = 0; i < 10; i++)
//    {
//        sum[i] = arr[i] + RightSide.arr[i];
//    }
    return sum;
    }
Polynomial operator*(const Polynomial& LeftSide, const Polynomial & RightSide)
{
    Polynomial product;
    product.del_size = LeftSide.del_size + RightSide.del_size;
    for (int i = 0; i < RightSide.del_size ; i++)
        //del_size wont work here say x^3 *x^3 we get max x^6
    {
//        product.arr[i]= RightSide.arr[i];
        for (int k = 0; k < LeftSide.del_size; k++ )
        {
            product.arr[k+i] += (LeftSide.arr[k] * RightSide.arr[i]);
            // need to make sure the products shift
            //then add those products
        }
    }
    //double for loop to make mupltiplication and then sum the products
    return product;
}
void Polynomial::operator=(const Polynomial & RightSide)
{
    for( int i = 0; i < RightSide.del_size; i++)
    {
        arr[i] = RightSide.arr[i];
    }
    del_size = RightSide.del_size;
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
//    cout << arr[0];
    for (int i = del_size - 1; i >= 0; i--)
    {
        if (i == 1 && !(arr[i] == 0))
        {
            cout << arr[i] << "x ";
        }
        else if ( i == 0 && !(arr[i] == 0))
        {
            cout << arr[i] << endl;
        }
        else if (!(arr[i] == 0))
        {
            cout << arr[i] << "x^" << i-1 << " ";
        }

//        for (int k + 0; k < i; k++)
//        {
//            cout << "^"
//        }
    }
    //make actual get with x and  make it empty if index is 0
}

int main() {
    // i need to find a way to transfer the size of the array
    Polynomial a(4);
    Polynomial b(4);
    Polynomial c;
    Polynomial k;
    a.set(1,2);
    a.set(0,1);
    a.set(2,2);
    a.set(3,0);
    a.set(4,5);
    b.set(1,2);
    b.set(0,1);
    b.set(2,4);
    b.set(3,2);
    b.set(4,6);
    a.get();
    cout  << "+" <<endl;
    b.get();
//    c = (a + b);
//    c.get();
    k = (a * b);
    k.get();
    return 0;
}
