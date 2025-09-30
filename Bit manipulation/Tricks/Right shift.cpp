#include<iostream>
using namespace std;

void print(int num)
{
    cout<<num<<" = ";
    for(int i=8; i>=0; --i)
        cout<< ((num>>i) & 1); // prints binary;
    cout<<endl;
}

int main()
{
    // Right shift removes the last digit of the binary of a number.

    int a=80;
    print(a);
    int b=a>>1;
    print(b);
    print(a>>2);
    print(a>>4);
    // It essentially divides a number by 2^x
}