/*
There are N children and K toffees. K < N
Count the number of ways to distribute toffee
among N students, such that each student gets 1 toffee only.

Constraints-> N < 10^6 and K < N < 10^6

ANS --> nCk == n!/((n-r)! * r!)

*/

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

long long exponent(long long x, long long n, long long m)
{
    long long ans = 1;
    while(n)
    {
        if(n & 1)
            ans = (ans * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return ans;
}

long long fact(long long n)
{
    long long result = 1;
    for(long long i = 2; i <= n; i++)
    {
        result = (result * i) % M;
    }
    return result;
}

int main()
{
    int n,k;
    cin>>n>>k;
    long long den = (fact(n-k) * fact(k)) % M;
    long long ans = (fact(n) * exponent(den, M-2, M)) % M;
    cout<<ans<<endl;
}