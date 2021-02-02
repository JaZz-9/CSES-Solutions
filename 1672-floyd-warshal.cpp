#include<bits/stdc++.h>
#define ll long long int
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vll>
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
    ll n,m,i,j,k; ll q; cin>>n>>m>>q;
     
    ll dp[n+1][n+1];
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(i==j) dp[i][j]=0;
            else dp[i][j]=MAXX;}
            
    vpii adj[n+1];
    for(i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        // adj[u].pb({v,w});
        dp[u][v]=min(w,dp[u][v]);
        dp[v][u]=min(w,dp[u][v]);
    }
   
            
    
    
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    
    for(i=1;i<=q;i++)
    {
        ll a,b; cin>>a>>b;
        if(dp[a][b]==MAXX) cout<<"-1\n";
        else cout<<dp[a][b]<<"\n";
    }
}
