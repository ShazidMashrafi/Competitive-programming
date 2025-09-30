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
    // In uppercase the 5th bit is unset and in lowercase it is set.

    // Uppercase to lowercase
    char uc='A';
    char lc= uc | (1<<5);
    cout<<uc<<": ";
    print(uc);
    cout<<lc<<": ";
    print(lc);

    // 1<<5 also means a blank space
    print(1<<5);
    print(' ');
    cout<<char(uc | ' ')<<endl;

    //Lowercase to uppercase
    lc='z';
    uc= lc & (~(1<<5));
    cout<<lc<<": ";
    print(lc);
    cout<<uc<<": ";
    print(uc);
    // ~(1<<5) == 111011111
    // but '_' can also do the trick. Because it is 001011111
    print(~(1<<5));
    print('_');
    cout<<char(lc & '_')<<endl;

    // Exchange letter case
    char c='n';
    cout<< char(c ^ (1<<5))<<endl;
}