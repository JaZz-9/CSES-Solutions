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
vi trace;

void dfs(int node)
{
    vis[node]=1;
    for(auto child:adj[node])
    {
        if(!vis[child])
            dfs(child);
    }
    trace.pb(node);
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
    
    vi dp(n+1,-1), parent(n+1,0);
    
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs(i);
            
    // for(auto i=0;i<n;i++)
        // cout<<trace[i]<<" ";
            
    reverse(trace.begin(), trace.end());        
    
    for(int i=0;i<n;i++)
    {
        int u=trace[i];
        if(u==n) break;
        if(u==1) dp[u]=1;
        if(dp[u]>0)
            for(int v: adj[u])
                if(dp[v] < dp[u]+1)
                    {
                        dp[v] = dp[u]+1;
                        parent[v] = u;
                    }
    }
   
    if(dp[n]<0)  
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    
    vi r(1, n);
    int u = n;
    while(u) 
    {
        u = parent[u]; 
        r.push_back(u);
        
    }
    reverse(r.begin(), r.end());
    cout << r.size()-1 << '\n';
    for (int i = 1; i < r.size(); i++)
      cout << r[i] << " ";

    
    return 0;
    
}