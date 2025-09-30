/*Problem
Given array a of N integers. Given Q queries and in each query given L and
R, print the sum of array elements from index L to R (L,R included)

Constrains
1<=N<=10^5
1<=Q<=10^5
1<=L,R<=10^5
1<=a[i]<=10^9
*/
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++) //for sums, array starting form 1th index is easier
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        long long sum=0;
        for(int i=l; i<=r; i++) //TLE
        {
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
}
*/

/*
We can use presum to solve the problem without TLE
We will declare an array for which s[i] will store the sum of s[1] to s[i];
if array is 5 7 9 11 13
s[3] will store the sum of the values 5+7+9
S[4] will store s[3]+11 thus 5+7+9+11
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int sum[N];

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]= sum[i-1]+a[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
        // s[r] contains sum of 1 to r
        // s[l-1] contains sum of 1 to l-1
        // so sum[r]-sum[l-1] will contain sum of l to r 
    }
}