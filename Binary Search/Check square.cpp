#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int L=0;
    int R=n;
    bool sq=0;
    while(L<=R)
    {
        int mid = L +(R-L)/2;
        if(mid*mid==n)
        {
            sq=1;
            break;
        }
        if(mid*mid<n)
            L = mid+1;
        else
            R = mid-1;
    }
    if(sq)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}