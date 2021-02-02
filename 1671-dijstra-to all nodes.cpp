#include<bits/stdc++.h>
#define ll long long int
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define pii pair<ll,ll>
#define vpii vector<pii>
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
using namespace std;

int main()
{
    io;
    ll n,m; cin>>n>>m;
    
    vpii adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
    }
    
    priority_queue<pii, vpii, greater<pii> > Q;
    Q.push({0,1});
    
    vll dis(n+1,1e16), vis(n+1,0);
    dis[1]=0;
    
    while(!Q.empty())
    {
        int u=Q.top().ss;
        Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v: adj[u])
        {
            int child=v.ff;
            ll wei=v.ss;
            if(!vis[child] && dis[child]>dis[u]+wei)
            {
                dis[child]=dis[u]+wei;
                Q.push({dis[child],child});
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
}
