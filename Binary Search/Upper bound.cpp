#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    int low=0, high=n-1, ans=-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(v[mid] <= x)
            low = mid+1;
        else
        {
            ans = mid;
            high = mid-1;
        }
    }
    if(ans==-1)
        cout<<"Not found"<<endl;
    else
        cout<<"Found at position "<<ans<<" value "<<v[ans]<<endl;
}