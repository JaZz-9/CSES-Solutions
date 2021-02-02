#include<bits/stdc++.h>
#define ll long long 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define pii pair <int,int>
#define vvi vector<vi>
#define vpii vector<pii> 
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
const int N=1e5+5;
vi topo, adj[N];
vector<bool> vis(N,false);
int d=0,ans=0;
void dfs(int node, int d)
{
    vis[node]=1;
    for(auto child:adj[node])
    {
        if(!vis[child])
            dfs(child,d+1);
    }
    ans=max(d,ans);
    // cout<<node<<" "<<d<<"\n";
    topo.pb(node);
}

int main()
{
    io;
    int i,n; cin>>n;
    for(i=0;i<n-1;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    dfs(1,0);
    int a=topo[0];
    // cout<<a<<" ";
    vis.assign(n+1,false);
    d=0;
    topo.clear();
    dfs(a,0);
    cout<<ans;
}