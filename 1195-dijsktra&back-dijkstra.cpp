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
const ll MAXX=1e18;

int main()
{
    io;
    ll n,m; cin>>n>>m;
    
    vpii adj[n+1], adjr[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v; ll w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adjr[v].pb({u,w});
    }
    
    priority_queue<pii, vpii, greater<pii> > Q,R;
    Q.push({0,1});
    
    vll da(n+1,1e16), vis(n+1,0);
    da[1]=0;
    
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
            if(!vis[child] && da[child]>da[u]+wei)
            {
                da[child]=da[u]+wei;
                Q.push({da[child],child});
            }
        }
    }
    vll db(n+1,1e16); vis=vll (n+1,0);
    db[n]=0;
    R.push({0,n});
    
    while(!R.empty())
    {
        int u=R.top().ss;
        R.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto v: adjr[u])
        {
            int child=v.ff;
            ll wei=v.ss;
            if(!vis[child] && db[child]>db[u]+wei)
            {
                db[child]=db[u]+wei;
                R.push({db[child],child});
            }
        }
    }
    
    // for(auto i:da) cout<<i<<" ";
    // cout<<"\n";
    // for(auto i:db) cout<<i<<" ";
    
    ll ans=MAXX;
    
    for(int i=1;i<=n;i++)
    {
        for(auto j: adj[i])
        {
            ans=min(ans, da[i]+db[j.ff]+(j.ss/2) );
        }
    }
    
    cout<<ans<<"\n";
}
