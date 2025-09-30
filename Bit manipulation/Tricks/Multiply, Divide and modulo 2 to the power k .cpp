#include<iostream>
using namespace std;

void print(int num)
{
    cout<<num<<": ";
    for(int i=8; i>=0; --i)
        cout<< ((num>>i) & 1); // prints binary;
    cout<<endl;
}

int main()
{
    int n=10;
    print(n);
    int i=1;
    cout<<"Multiply and divide by 2^"<<i<<": "<<endl;
    print(n<<i);
    print(n>>i);
    i=2;
    cout<<"Multiply and divide by 2^"<<i<<": "<<endl;
    print(n<<i);
    print(n>>i);

    cout<<"Modulo of 2^"<<i<<": "<<endl;
    print(n & ((1<<i)-1));
}