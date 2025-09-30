#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    cout<<gcd(4,12)<<endl;
    cout<<gcd(12,18)<<endl;
    cout<<gcd(1,18)<<endl;
    cout<<12*18/gcd(12,18)<<endl;
    cout<<gcd(4,gcd(12,18))<<endl;
}
