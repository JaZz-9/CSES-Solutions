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

bool dfs(int node)
{
    color[node]=1;
    for(auto child:adj[node])
    {
        // cout<<node<<" "<<child<<"\n";
        if(color[child]==0)
        {
            bool flag=dfs(child);
            if(flag) 
            {
            	
            	if(!stop)
            	Q.push(child); 
            	if(node==stopper) stop=1; 
            	return true;}
        }
        else if(color[child]==1) 
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
    }
    
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            bool flag=dfs(i);
            if(flag)
            {
            	int siz=Q.size()+2;
            	cout<<siz<<"\n";
            	vi ans(siz);
            	ans[0]=ans[siz-1]=stopper;
            	int j=siz-2;
                while(!Q.empty())
                {
                    ans[j]=Q.front();
                    Q.pop();
                    j--;
                }
                for(auto f:ans) cout<<f<<" ";
                return 0;
            }
            
        }
    }
    
    cout<<"IMPOSSIBLE\n"; return 0;
    
}