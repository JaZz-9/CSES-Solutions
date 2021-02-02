#include<bits/stdc++.h>
#define ll long long 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define pii pair <int,int>
#define vvi vector<vi>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
const int N=1e5+5;
vector<bool> vis(N,false);
vi component, adj[N], adjr[N];
// vvi sccs;
stack<int> S;

void dfs1(int node)
{
    vis[node]=true;
    for(auto child:adj[node])
        if(!vis[child])
            dfs1(child);
            
    S.push(node);
}

void dfs2(int node)
{
    vis[node]=true;
    for(auto child:adjr[node])
        if(!vis[child])
            dfs2(child);
    
    component.pb(node);
}

int main()
{
    int n,m;
     cin>>n>>m;
     
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adjr[b].pb(a);
    }
    
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs1(i);
            
            
    vis.assign(n+1,false);
    int kingdom=1;
    vi ans(n+1,0);
    
    while(!S.empty())
    {
        int t=S.top(); S.pop();
        if(vis[t]) continue;
        
        component.clear();
        dfs2(t);
        for(auto i:component) 
            ans[i]=kingdom;
        
        kingdom++;
        // cout<<"\n";
    }
    
    
    cout<<kingdom-1<<"\n";
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    
    cout<<"\n";
    
}