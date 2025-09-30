#include<iostream>
using namespace std;

int main()
{
    int a=4,b=6;
    cout<<"a: "<<a<<" b: "<<b<<endl;
    a = a ^ b; // here a = 4 and b = 6. So, a =  4 ^ 6;
    b = b ^ a; // Here b = 6 and a =  4 ^ 6. So, b = 6 ^ 4 ^ 6 = 4;
    a = a ^ b; // Here a = 4 ^ 6 and b = 4. So, a = 4 ^ 6 ^ 4 = 6
    cout<<"a: "<<a<<" b: "<<b<<endl;
}