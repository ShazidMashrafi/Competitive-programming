#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

// a ^ b % M ==  a ^ ( b% (M-1) ) % M       if M is prime

long long exponent(long long a, long long b, long long m)
{
    a %= m;             
    long long ans = 1;
    while(b)
    {
        if(b & 1)
            ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int main()
{
    // 50^(60^32)
    cout<<exponent(50,exponent(60,32,M-1),M)<<endl;
}