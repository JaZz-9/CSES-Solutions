#include<bits/stdc++.h>
#define ll long long int
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define pii pair <int,int>
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
const int N=1e5+5;

int rnk[N];
int par[N];

void make_set(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        rnk[i]=1;
    }
}

int find_set(int x)
{
    if(par[x]==x)
        return x;
    
    return par[x]=find_set(par[x]);
}

void union_set(int a,int b)
{
    int p1=find_set(a);
    int p2=find_set(b);
    if(p1==p2)
        return;
    if(rnk[p1]>rnk[p2])
    {
        par[p2]=p1;
        rnk[p1]=rnk[p1]+rnk[p2];
    }
    else
    {
        par[p1]=p2;
        rnk[p2]=rnk[p1]+rnk[p2];
    }
}

int main()
{
    int n,m; cin>>n>>m;
    multiset< pair<ll,pii> >S;
    make_set(n);
    
    while(m--)
    {
        int a,b; cin>>a>>b;
        ll c; cin>>c;
        S.insert({c,{a,b}});
    }
    
    ll sum=0, cnt=0;
    
    for(auto edge: S)
    {
        int u=edge.ss.ff, v=edge.ss.ss;
        ll w=edge.ff;
        
        if(find_set(u)==find_set(v)) continue;
        
        union_set(u,v);
        sum+=w;
        cnt++;
        if(cnt==n-1) break;
    }
    
    if(cnt==n-1) cout<<sum<<"\n";
    else cout<<"IMPOSSIBLE\n";
}