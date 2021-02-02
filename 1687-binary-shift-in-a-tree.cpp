#include <bits/stdc++.h>
#define int long long
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
 
#define die(x) return cout << x << '\n', 0;
 
using namespace std;
 
int n;
vector<int> par;
vector<vector<int> > dp;
 
const int x = 24;  // You can also use x=log2(n)+1
 
void build() {
  for (int i = 0; i < n; i++) dp[i][0] = par[i];
  for (int j = 1; j <= x; j++) {
    for (int i = 0; i < n; i++) {
      if (dp[i][j - 1] == -1)
        dp[i][j] = -1;
      else
        dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }
  }
}
 
int query(int s, int k) {
  for (int i = x; i >= 0; i--) {
    if ((1 << i) <= k) {
      s = dp[s][i];
      k -= (1 << i);
      if (s == -1) return -1;
    }
  }
  return s + 1;
}
 
int32_t main() {
  fastio;
  int q;
 
  cin >> n >> q;
  par.resize(n);
  par[0] = -1;
  for (int i = 1; i < n; i++) {
    cin >> par[i];
    par[i]--;
  }
  dp.assign(n, vector<int>(x + 1, -1));
  build();
  int node, k;
  while (q--) {
    cin >> node >> k;
    node--;
    cout << query(node, k) << '\n';
  }
 
  }