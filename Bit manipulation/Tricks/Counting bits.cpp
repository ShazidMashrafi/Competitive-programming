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
    int a=9,b=13;
    print(a);
    int ct=0;
    for(int i=31; i>=0; --i)
    {
        if((a&(1<<i))!=0)
            ct++;
    }
    cout<<ct<<endl;
    print(b); 
    ct=0;
    for(int i=31; i>=0; --i)
    {
        if((b&(1<<i))!=0)
            ct++;
    }
    cout<<ct<<endl;

    cout<<__builtin_popcount(a)<<endl;  //builtin function to count set bits of integers
    cout<<__builtin_popcountll((1LL<<35)-1)<<endl;
}