#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_studio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pb push_back
using namespace std;
const int N=2e5+1;
const int x=24;
int n;
vi adj[N];
int par[N][x+1];
int depth[N];
int vis[N];
void dfs(int node, int parent)
{
    par[node][0]=parent;
    vis[node]=1;
    // cout<<node<<" "<<parent<<"\n";

    for(int j=1;j<x;j++)
        {
            par[node][j]=par[ par[node][j-1] ][j-1];
            // cout<<par[node][j-1]<<" "<<par[node][j]<<"\n";
        }
    
    for(auto child:adj[node])
    {
        if(child!=parent && vis[child]==0)
        {
            depth[child]=depth[node]+1;
            dfs(child,node);
        }
    }
}

int find_kth(int node, int k)
{
    for(int j=x;j>=0;j--)
    {
        if((1<<j)&k)
        {
            node=par[node][j];
            k-=(1<<j);
        }
    }
    return node;
}

int lca(int a, int b)
{
    if(depth[a]>depth[b])
        swap(a,b);
    
    int d=depth[b]-depth[a];
    b=find_kth(b,d);
    // cout<<b<<" ";
    if(a==b)
        return a;
    
    for(int j=x;j>=0;j--)
    {
        if(par[a][j]!=par[b][j])
        {
            a=par[a][j];
            b=par[b][j];
        }
    }
    // cout<<a<<" ";
    return par[a][0];
}

int main()
{
        int q;
        cin>>n>>q;
        
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>v;
            adj[v].pb(i+1);
        }
        dfs(1,1);
        
        // for(int i=1;i<=n;i++)
        // {
        //     for(int j=0;j<24;j++)
        //         cout<<par[i][j]<<" ";
        //     cout<<"\n";    
        // }

        while(q--)
        {
            int u,v; 
            cin>>u>>v;
            cout<<lca(u,v)<<"\n";
        }
    
    return 0;
}