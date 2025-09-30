#include<iostream>
using namespace std;

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
    // Even odd check
    // If n is odd, n&1 will return 1, if even it will return 0

    cout<<"5: ";
    print(5);
    cout<<"6: ";
    print(6);
    cout<<"1: ";
    print(1);
    cout<<"For 5: "<<endl;
    cout<<"5 & 1: ";
    print(5&1);
    if(5&1)
        cout<<"Odd"<<endl;
    else
        cout<<"Even"<<endl;
    cout<<"For 6: "<<endl;
    cout<<"6 & 1: ";
    print(6&1);
    if(6&1)
        cout<<"Odd"<<endl;
    else
        cout<<"Even"<<endl;
    
}