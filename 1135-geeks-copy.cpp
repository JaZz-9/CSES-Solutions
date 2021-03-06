// C++ program to find diameter of a binary tree
// using DFS.

#include <iostream>
#include <limits.h>
#include <list>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using namespace std;
 
// Used to track farthest node.
int x;
 
// Sets maxCount as maximum distance from node.
void dfsUtil(int node, int count, bool visited[],
                   int& maxCount, list<int>* adj)
{
    visited[node] = true;
    count++;
    for (auto i = adj[node].begin(); i != adj[node].end(); ++i) {
        if (!visited[*i]) {
            if (count >= maxCount) {
                maxCount = count;
                x = *i;
            }
            dfsUtil(*i, count, visited, maxCount, adj);
        }
    }
}
 
// The function to do DFS traversal. It uses recursive
// dfsUtil()
void dfs(int node, int n, list<int>* adj, int& maxCount)
{
    bool visited[n + 1];
    int count = 0;
 
    // Mark all the vertices as not visited
    for (int i = 1; i <= n; ++i)
        visited[i] = false;
 
    // Increment count by 1 for visited node
    dfsUtil(node, count + 1, visited, maxCount, adj);
}
 
// Returns diameter of binary tree represented
// as adjacency list.
int diameter(list<int>* adj, int n)
{
    int maxCount = INT_MIN;
 
    /* DFS from a random node and then see
    farthest node X from it*/
    dfs(1, n, adj, maxCount);
 
    /* DFS from X and check the farthest node
    from it */
    dfs(x, n, adj, maxCount);
 
    return maxCount;
}
 
/* Driver program to test above functions*/
int main()
{
    io;
    int i,n; cin>>n;
    if(n==1) 
    {
        cout<<"0";
        return 0;
    }
    list<int>* adj = new list<int>[n + 1];
    
    for(i=0;i<n-1;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
  
    /* maxCount will have diameter of tree */
    cout<< diameter(adj, n)-1 << endl;
    return 0;
}