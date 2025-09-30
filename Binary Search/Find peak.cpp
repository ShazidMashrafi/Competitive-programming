#include<bits/stdc++.h>
using namespace std;

int peak(vector<int>&v, int low, int high)
{
    int ans=-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(v[mid]>v[mid-1] || mid==0)
        {
            ans=mid;
            low = mid +1;
        }
        else
            high = mid-1;
    }
    return v[ans];
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &x:v)  cin>>x;
    cout<<peak(v,0,n-1)<<endl;
}