#include<bits/stdc++.h>
using namespace std;
#define ll 	long long

const int M = 1e9+7;

const int N=1e5+10;
vector<int>g[N];
int subtree_sum[N];
void dfs(int v, int parent)
{
    subtree_sum[v] += v;
    for(int child : g[v])
    {
        if(child==parent)
            continue;
        dfs(child,v);
        subtree_sum[v] += subtree_sum[child];
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n-1; ++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1);
    long long ans=0;
    for(int i=2; i<=n;++i)
    {
        int part1=subtree_sum[i];
        int part2=subtree_sum[1]-part2;
        ans= max(ans, (part1*1LL*part2));
    }
}