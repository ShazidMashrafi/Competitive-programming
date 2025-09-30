#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int exponent(int a, int b)
{
    if(b==0)
        return 1;
    int res = exponent(a,b/2);
    if(b&1)
        return (a * ((res * 1LL * res) % M)) % M;  // If long long is taken instead of int then
    else                                          // no needed.
        return (res * 1LL * res) % M;
}

int main()
{
    cout<<exponent(2,13)<<endl;
}