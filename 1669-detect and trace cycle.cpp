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
vi color(N+1,0);
queue<int>Q;
int stopper=0,stop=0;

bool dfs(int node, int par)
{
    color[node]=1;
    for(auto child:adj[node])
    {
        // cout<<node<<" "<<child<<"\n";
        if(color[child]==0)
        {
            bool flag=dfs(child,node);
            if(flag) 
            {
                
                if(!stop)
                Q.push(child); 
                if(node==stopper) stop=1; 
                return true;}
        }
        else if(color[child]==1 && child!=par) 
        {
            stopper=child;
            return true;
        }
    }
    color[node]=2;
    return false;
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
    
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            bool flag=dfs(i,-1);
            if(flag)
            {
                cout<<Q.size()+2<<"\n";
                cout<<stopper<<" ";
                while(!Q.empty())
                {
                    cout<<Q.front()<<" ";
                    Q.pop();
                }
                cout<<stopper<<" ";
                return 0;
            }
            
        }
    }
    
    cout<<"IMPOSSIBLE\n"; return 0;
    
}