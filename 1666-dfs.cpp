#include<bits/stdc++.h>
#define ll long long int
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define pii pair<int,int>
using namespace std;
const int N=1e5+5;
vector<int> adj[N+1];
queue<int> Q,Q1;
vector<int> vis(N+1,0);

bool dfs(int node)
{
    vis[node]=1;
    for(auto child:adj[node])
    {
        if(!vis[child])
            dfs(child);
    }
    Q.push(node);
}

int main()
{
    int n,m; cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int cluster=0;
    vector<pii> ans;
    
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) 
        {
            if(cluster&&Q.front()!=i)
            ans.pb({Q.front(),i});
            dfs(i);
            
            Q=Q1;
            cluster++;            
        }
        
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans)
    {
        cout<<i.ff<<" "<<i.ss<<"\n";
    }
    return 0;
}