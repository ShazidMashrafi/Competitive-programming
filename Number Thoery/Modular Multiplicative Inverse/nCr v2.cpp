/*
There are N children and K toffees. K < N.
Each case will contain Q queries.
Count the number of ways to distribute toffee
among N students, such that each student gets 1 toffee only.

Constraints-> N < 10^6 and K < N < 10^6  and Q < 10^5

ANS --> nCk == n!/((n-r)! * r!)

*/

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
const int N = 1e6+10;
int fact[N];

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

int main()
{
    fact[0]=1;
    for(int i=1; i<N; ++i)
        fact[i] = (fact[i-1] * 1LL * i)%M;
    int q;
    cin>>q;
    while(q--)
    {
        int n,k;
        cin>>n>>k;
        int dem = (fact[n-k] * 1LL * fact[k]) % M;
        int ans = (fact[n] * 1LL * exponent(dem,M-2,M)) % M;
        cout<<ans<<endl;
    }
}