#include<bits/stdc++.h>
using namespace std;
#define ll 	long long

const int N=1e5+10;
vector<int>g[N];
int subtree_sum[N];
int even_ct[N];

void dfs(int vertex, int parent)
{
    //Take action on vertex after entering the vertex
    subtree_sum[vertex] +=vertex;
    if(vertex%2==0) 
        even_ct[vertex]++;
    for(int child : g[vertex])
    {
        // Take action on child before entering child node
        if(child==parent)   
            continue;
        dfs(child,vertex);
        // Take action on child after exiting child node
        subtree_sum[vertex] += subtree_sum[child];
        even_ct[vertex] += even_ct[child];
    }
    //Take action on vertex before exiting the vertex
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

    dfs(1,0);
    for(int i=1; i<=n; ++i)
    {
        cout<<subtree_sum[i]<<" "<< even_ct[i]<<endl;
    }

    // int q;
    // cin>>q;
    // while(q--)
    // {
    //     int v;
    //     cin>>v;
    //     cout<<subtree_sum[v]<<" "<<even_ct[v]<<endl;
    // }
} 