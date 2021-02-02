#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_studio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
using namespace std;
const int N=2e5+5;
const ll mod=1e9+7;
vi adj[N];
vll cnt(N),dp(N),ans(N);

void dfs1(int node, int par)
{
    cnt[node]=1;
    dp[node]=0;
    for(auto it:adj[node])
    {
        if(it==par) continue;
        dfs1(it,node);
        cnt[node]+=cnt[it];
        dp[node]+=(dp[it]+cnt[it]);
    }
}

ll dfs2(int node, int par)
{
    ans[node]=dp[node];
    ll s1=cnt[node];
    ll t1=dp[node];
    for(auto j:adj[node])
    {
        if(j==par) continue;
        ll s2=cnt[j];
        ll t2=dp[j];
        
        cnt[node]-=cnt[j];
        dp[node]-=(dp[j]+cnt[j]);
        
        cnt[j]+=cnt[node];
        dp[j]+=(dp[node]+cnt[node]);
        
        dfs2(j,node);
        
        cnt[node]=s1;
        cnt[j]=s2;
        
        dp[node]=t1;
        dp[j]=t2;
    }
}

int main()
{
    // io;
    int n;
    cin>>n;
    // memset(dp,-1,sizeof(dp));
    for(int i=0;i<n-1;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    dfs1(1,1);
    dfs2(1,1);
    
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    
    
}