#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

// a>=10^18  
long long exponent(long long a, long long b)
{
    a %= M;             // (a^b)%M == ((a%M)^b)%M
    long long ans = 1;
    while(b)
    {
        if(b & 1)
            ans = ans * a;
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}

int main()
{
    cout<<exponent(2,13)<<endl;
}