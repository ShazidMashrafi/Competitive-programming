#include<bits/stdc++.h>
using namespace std;

// M > 10^9

const long long M = 1e18+7;

long long bin_multiply(long long a, long long b)
{
    long long ans = 0;
    while(b>0)
    {
        if(b & 1)
            ans = (ans + a) % M;
        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}

long long exponent(long long a, long long b)
{
    long long ans = 1;
    while(b)
    {
        if(b & 1)
            ans = bin_multiply(ans, a);
        a = bin_multiply(a,a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    cout<<exponent(2,13)<<endl;
}