/*Problem
Given 2d array a of N*N integers. Given Q queries and in each query given a, b, c and d
print sum of square represented by (a,b) as top left point and (c,d) as bottom right point.

Constrains
1 <= N <= 10^3
1 <= a[i][j] <= 10^9
1 <= Q <= 10^5
1<= a, b, c, d <=N
*/
/*
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int arr[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) // O(N^2)
    {
        for(int j = 1; j <= n; j++) // O(N)
        {
            cin>>arr[i][j];
        }
    }
    int q;
    cin>>q;
    while(q--) // O(Q*N^2) = 10^5*10^3*10^3=10^11
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        long long sum=0;
        for(int i=a; i <=c; i++) // O(N^2)
        {
            for(int j=b; j<=d; j++) // O(N)
            {
                sum+=arr[i][j];
            }
        }
        cout<<sum<<endl;
    }
}
*/

/*
Will get TLE on upper code.
To solve this problem we can pre compute the sums of the arrays on a 2D array beforehand.
Example,
A[2][3] will store sums of all the values of square arr[1][1] arr[1][3] arr[2][1] arr[2][3]
A[4][3] will store sum of all the values of square arr[1][1] arr[1][3] arr[1][4] arr[4][3]
A[3][5] will store sum of all the values of square arr[1][1] arr [1][5] arr[1][3] arr[3][5]
https://youtu.be/nZe7P674xZo?t=850
if we want to store the sum of 3,3 then we need to do
A[3][3]= arr[3][3]+A[2][3]+A[3][2]-A[2][2] 
we need to minus A[2][2] because A[2][2] is common in both of them.
Thus A[i][j]= arr[i][j]+A[i-1][j]+A[i][j-1]-A[i-1][i-1]

Then if want to show from square 1,2 to 3,3
then A[3][3]-A[1-1][3]-A[3][2-1]+A[1-1,2-1]
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int arr[N][N];
long long pf[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>arr[i][j];
            pf[i][j]=arr[i][j]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1]<<endl;
    }
}