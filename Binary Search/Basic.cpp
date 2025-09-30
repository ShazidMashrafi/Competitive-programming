#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    
    int low=0, high=n-1, ans=-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(v[mid]==target)
        {
            ans = mid;
            break;
        }
        else if(v[mid]<target)
            low = mid+1;
        else
            high = mid-1;
    }
    cout<<ans<<endl;
}