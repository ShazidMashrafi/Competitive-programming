/*Problem
Given T test cases and in each test case a number N. Print its factorial
for each test case % M
where M=10^9+7

Constrains 
1<=T<=10^5
1<=N<=10^5
*/

/*
#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;

int main()
{
    int t;
    cin>>t;
    while(t--) // O(T*N)=10^5*10^5=10^10
    {
        int n;
        cin>>n;
        long long fact=1;
        for(int i=2;i<=n;i++)
        {
            fact=(fact*i)%M;
        }
        cout<<fact<<endl;
    }
}
*/

/*
Upper code will get TlE because it is nested
To not get a TLE we can pre compute all the factorial values upto N and store them
in their corresponding index in an array. Then we can only output the values user wants, we don't need to compute every time.
Example,
fact[3] will contain 6 which is the factorial of 3
fact[5] will contain 120 which is the factorial of 5
*/

#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
const int N=1e5+10;

int fact[N];

int main()
{
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++) // O(N)=10^5
    {
        fact[i]=(fact[i-1]*i)%M;
    }
    int t;
    cin>>t;
    while(t--) // O(T)=10^5
    {
        int n;
        cin>>n;
        cout<<fact[n]<<endl;
    }
}