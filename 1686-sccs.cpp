#include<bits/stdc++.h>
#define ll long long 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mod 1000000007
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vpii vector<pair<int,int> >
#define pb push_back
#define ff first
#define ss second
using namespace std;
const int N=1e5+5;

vi topo,new_topo,comp,code(N,0);
vll coins(N,0), new_coin(N,0);
vector<bool> vis(N,false);
vi adj[N],radj[N];
int id=0;
void dfs(int node)
{
    vis[node]=1;
    for(auto child: adj[node])
    {
        if(!vis[child])
            dfs(child);
    }
    topo.pb(node);
}

void dfs2(int node)
{
    vis[node]=1;
    comp.pb(node);
    code[node]=id;
    new_coin[id]+=coins[node];
    for(auto child: radj[node])
    {
        if(!vis[child])
            dfs2(child);
    }
}

int main()
{
    int n,m; cin>>n>>m;
    coins.resize(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];
    
    vpii edges;
    
    while(m--)
    {
        int u,v; cin>>u>>v; u--;v--;
        adj[u].pb(v);
        radj[v].pb(u);
        edges.pb({u,v});
    }
    
    vis.assign(n,false);
    
    for(int i=0;i<n;i++)
        if(!vis[i])
            dfs(i);
    
    vis.assign(n+1,false);            
    reverse(topo.begin(), topo.end());
    code.resize(n);
    new_coin.resize(n);
    
    for(int i=0;i<n;i++)
    {
        int t=topo[i];
        if(vis[t]) continue;
        
        comp.clear();
        dfs2(t);
        // scc.pb(comp);
        id++;
    }
    
    
    vi new_topo;
    set<int> st;
    for(int i=0;i<n;i++)
    {
        int new_node=code[topo[i]];
        if(!st.count(new_node))
        {
            st.insert(new_node);
            new_topo.pb(new_node);
        }
    }
    
    reverse(new_topo.begin(), new_topo.end());
    
    vvi new_adj(id);
    
    for(auto e:edges)
    {
        int u,v;
        u=code[e.ff]; 
        v=code[e.ss];
        if(u!=v) new_adj[u].pb(v);
    }
    
    vll dp(id,0);
    
    for(auto u:new_topo)
    {
        for(auto v:new_adj[u])
            dp[u]=max(dp[u], dp[v]);
        dp[u]+=new_coin[u];
    }
    
    // for(auto u:dp) cout<<u<<" ";
    
    cout<<*max_element(dp.begin(), dp.end());
    
}