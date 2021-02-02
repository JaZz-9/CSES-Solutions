#include<bits/stdc++.h>
#define ll long long int
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
using namespace std;
const int N=1e5+5;
vector<int> adj[N+1];
vi color(N+1,0);
bool dfs(int node, int curc)
{
    color[node]=curc;
    for(auto i:adj[node])
    {
        if(color[i]==color[node]) 
            return false;
        if(color[i]==0)
        {
            bool temp=dfs(i,3-color[node]);
            if(!temp)
                return false;
        }
    }
    return true;
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
    int flag=0;
    
    for(int i=0;i<n;i++)
    {
        if(color[i]==0)
        {
            bool temp=dfs(i,1);
            if(!temp)
            {
                cout<<"IMPOSSIBLE\n"; return 0;
            }
        }
    }
    
    for(int i=1;i<=n;i++) cout<<color[i]<<" ";
    
    return 0;
    
}