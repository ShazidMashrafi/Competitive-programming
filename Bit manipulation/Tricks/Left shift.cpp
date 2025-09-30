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
    // Left shit adds 0 to the end of the binary of a number.
    int a=5;
    print(a);
    int b=a<<1; 
    print(b);
    b=a<<2;
    print(b);
    b=a<<4;
    print(b);
    // It essentially multiplies a number by 2^x

    // Left shift operator can do 2^i. It's faster than pow function.
    int c=1;
    int d= c<<2;
    print(c<<4); 
}
