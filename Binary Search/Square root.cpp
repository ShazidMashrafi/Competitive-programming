#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x;
    cin>>x;
    double eps=1e-6;  // will give accuracy till 5 decimal places
    double lo=1, hi=x, mid;
    while(hi-lo>eps)
    {
        mid=(lo+hi)/2;
        if(mid*mid<x)
            lo = mid;
        else
            hi=mid;
    }
    cout<<lo<<endl;     
}