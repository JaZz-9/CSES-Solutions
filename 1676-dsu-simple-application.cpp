#include<bits/stdc++.h>
#define ll long long int
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define pb push_back
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
    make_set(n);
    int nc=n,mr=0;
    while(m--)
    {
        int a,b; cin>>a>>b;
        
        int p1,p2; 
        p1=find_set(a);
        p2=find_set(b);
        
        if(p1!=p2) nc--;
        union_set(a,b);
        
        mr=max({mr,rnk[find_set(a)], rnk[find_set(b)] });
        
        cout<<nc<<" "<<mr<<"\n";
    }
    
}