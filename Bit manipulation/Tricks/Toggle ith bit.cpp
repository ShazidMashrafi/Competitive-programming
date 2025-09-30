#include<iostream>
using namespace std;

void print(int num)
{
    for(int i=8; i>=0; --i)
        cout<< ((num>>i) & 1); // prints binary;
    cout<<endl;
}

int main()
{
    int a=9;
    print(a);
    int i=2;
    print(1<<i);
    print( a ^ (1<<i));
}