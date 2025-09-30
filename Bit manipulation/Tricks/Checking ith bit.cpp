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
    int a=9;
    print(9);
    int i=2;
    if((a & (1<<i))!=0)
        cout<<"Set"<<endl;
    else
        cout<<"Unset"<<endl;

}