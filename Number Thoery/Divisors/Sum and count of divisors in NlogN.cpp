#include<bits/stdc++.h>
using namespace std;

const int N = 10^7 +10;
vector<int>divisors[N];
int sum[N];

int main()
{
    for(int i=2; i<N; ++i)
    {
        for(int j=i; j<N; j+=i)
        {
            divisors[j].push_back(i);
            sum[j] += i;
        }
    }

    for(int i=1; i<10; ++i)
    {
        cout<<i<<"-> [ ";
        for(int divisor:divisors[i])
        {
            cout<<divisor<<" ";
        }
        cout<<"] Count: "<<divisors[i].size()<< " and Sum: "<<sum[i]<<endl;
    }
}