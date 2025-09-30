#include<bits/stdc++.h>
using namespace std;

const int N = 10^7 +10;
vector<bool>isPrime(N,1);
vector<int>lp(N,0), hp(N,0);

int main()
{
    isPrime[0]=isPrime[1]=0;
    for(int i=2; i<N; ++i)
    {
        if(isPrime[i])
        {
            lp[i]=hp[i]=i;
            for(int j=2*i; j<N; j+=i)
            {
                isPrime[j]=0;
                hp[j]=i;
                if(lp[j]==0)
                    lp[j]=i;
            }
        }
    }
    for(int i=1; i<100; ++i)
    {
        cout<<i<<" "<<lp[i]<<" "<<hp[i]<<endl;
    }
}