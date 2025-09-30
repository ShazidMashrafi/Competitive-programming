#include<bits/stdc++.h>
using namespace std;

int minimum(vector<int> &v, int l, int r)
{
    int ans=v[0];
    while(l<=r)
    {
        if(v[l]<=v[r])
            return min(ans,v[l]);
        int m = l + (r-l)/2;
        ans = min(ans,v[m]);
        if(v[m]>= v[l])
            l = m+1;
        else
            r = m -1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &x:v)  cin>>x;
    cout<<minimum(v,0,n-1)<<endl;
}