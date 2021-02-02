#include<bits/stdc++.h>
#define ll long long int
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
using namespace std;
const int N=1e5+5;
vector<int> adj[N+1];
stack<int> stk;
vector<int> vis(N+1,0);

bool dfs(int node)
{
    vis[node]=1;
    for(auto child:adj[node])
    {
        if(vis[child]==0)
        {
            bool flag=dfs(child);
            if(flag==true) return true;
        }
        else if(vis[child]==1)
            return true;
    }
    vis[node]=2;        
    stk.push(node);
    return false;
}

int main()
{
    int n,m; cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].pb(v);
    }
    
    vi ans;
    
    for(int i=1;i<=n;i++)
    {
        bool cycle=false;
        if(!vis[i])
            cycle=dfs(i);
        
        if(cycle) {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        
    }
    
    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    
    return 0;
}