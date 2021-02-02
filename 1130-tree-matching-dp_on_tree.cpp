#include<bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_studio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
#define pb push_back
using namespace std;
const int N=2e5+5;
const ll mod=1e9+7;
vi adj[N];
int dp[N][3];

int dfs(int node, int prev, int par)
{
    if(dp[node][prev]!=-1) return dp[node][prev];
    int sum=0; 
    int res=0;
    for(auto j:adj[node])
    {
        if(j!=par)
            sum+=dfs(j,0,node);    // 0 indicates child-parent edge  picked
    }
    res=sum;
    
    if(prev!=1)                   // 1 indicates child-parent edge not picked
    {
        for(auto j:adj[node])
        {
            if(j!=par)
            {
                int tmp=dfs(j,1,node)+1;
                int tmp2=dfs(j,0,node);
                res=max(res,sum-tmp2+tmp);
            }
        }
    }
    return dp[node][prev]=res;
}
int main()
{
    // io;
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n-1;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    cout<<dfs(1,2,1);
    
}