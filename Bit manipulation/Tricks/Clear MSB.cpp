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
    int a=59;
    print(a);

    // If we need to clear til 3rd MSB of 59 = 000111011
    // then we need to & with            000001111
    //we can get this from               000010000 - 1

    int i=3;
    print(1<<(i+1));
    print((1<<(i+1))-1);
    print(a & ((1<<(i+1))-1));
}