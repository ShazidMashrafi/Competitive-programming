#include<bits/stdc++.h>
using namespace std;
#define ll 	long long

const int N = 1e5+10;
vector<int>g[N];
int vis[N];

void dfs(int vertex)
{
    //Take action on vertex after entering the vertex
    vis[vertex] = true;
    for(int child : g[vertex])
    {
        if(vis[child])  continue;
        // Take action on child before entering the child node
        dfs(child);
        // Take action on child after entering child mode
    }
    // Take action on vertex before exiting the vertex.
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; ++i)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
}