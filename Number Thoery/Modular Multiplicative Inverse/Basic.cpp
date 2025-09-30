#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

long long exponent(long long x, long long n, long long m)
{
    long long ans = 1;
    while(n)
    {
        if(n & 1)
            ans = (ans * x)%m;
        x = (x * x)%m;
        n >>= 1;
    }
    return ans;
}

int main()
{
    int a;
    cin>>a;
    cout<<exponent(a,M-2,M)<<endl;
}