#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    double x;
    cin>>x;
    int n;
    cin>>n;
    double eps=1e-6;
    double low=1, high=x,ans;
    while(high-low>=eps)
    {
        double mid = low+(high-low)/2;
        if(pow(mid,n)<=x)
        {    
            low = mid+eps;
            ans = mid;
        }
        else
            high = mid-eps;
    }
    cout<<ans<<endl;     
}