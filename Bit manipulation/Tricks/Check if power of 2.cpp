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
    int x=64;
    print(x);
    print(x-1);
    print(x & (x-1));

    // if x & x-1 is 0 then it is power of 2.
    // It does not work for the case x==0. This is a edge case.
    // 0 & 0-1 will also return 0 but it not a power of 2.
    x=0;
    print(x);
    print(x-1);
    print(x & (x-1));
}