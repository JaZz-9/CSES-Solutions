#include<bits/stdc++.h>
#define ll long long int
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define pb push_back
#define mod 1000000007
using namespace std;
const int N=2e5+5;
vector<int> adj[N+1];
vi vis(N+1,0);
stack<int> S;

void dfs(int node)
{
    vis[node]=1;
    for(auto v: adj[node])
    {
        if(!vis[v])
        {
           dfs(v); 
        }
    }
    S.push(node);
}
 

int main()
{
    io;
    int n,m; cin>>n>>m;
    
    for(int i=0;i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    
    vi dp(n+1,0), parent(n+1,0);
    
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    
    while(!S.empty())
    {
        int u=S.top();
        S.pop();
        // cout<<u<<" ";
        for(auto v:adj[u])
        {
            if(dp[v]<=dp[u]+1)
            {
                dp[v]=dp[u]+1;
                parent[v]=u;
            }
        }
    }
    
    vi ans;
   
     // cout<<"\n";
      
    // for(int i=1;i<=n;i++) cout<<parent[i]<<" ";
    
   
    
    for(int i=n;i!=0;i=parent[i])
        ans.pb(i);
    
    // cout<<"\n";
    if(ans.back()!=1) cout<<"IMPOSSIBLE\n";
    
    else
    {
        cout<<ans.size()<<"\n";
        for(int i=int(ans.size())-1;i>=0;i--)
            cout<<ans[i]<<" ";
    }
    
    return 0;
    
}