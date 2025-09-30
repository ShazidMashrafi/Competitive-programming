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
    // If n = 10000
    // Then n-1 = 10000 - 1 = 01111
    print(1<<5);
    print((1<<5)-1);
    cout<<endl;
    // If we want to clear upto 4 LSB of 59 =  000111011 then
    // we need to & operation with        111100000
    // we can get that using inversion of 000011111
    // we can also get that from          000100000 - 1
    int a=59;
    int i=4;
    print(a);
    print(1 << (i + 1) );
    print( (1 << (i + 1) ) - 1);
    print( ~( (1 << (i + 1) ) - 1));
    print(a & ( ~((1<< (i + 1)) - 1)));
}