#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 9;
vector<int> g[N];
ll ans[N], col[N], sz[N], cnt[N];
bool big[N];
ll mxcnt,sum;
void dfs(int u, int p) {
    sz[u] = 1;
    for (auto v : g[u]) {
      if (v == p) continue;
      dfs(v, u);
      sz[u] += sz[v];
    }
}
void add(int u, int p, int x) {
    cnt[col[u]] += x;
    if(cnt[col[u]] == 1)sum++;
    else if(cnt[col[u]] == 0)sum--;
    for (auto v : g[u]) {
       if (v == p || big[v] == 1) continue;
       add(v, u, x);
    }
}
void dsu(int u, int p, bool keep) {
    int bigchild = -1, mx = -1;
    for (auto v : g[u]) {
       if (v == p) continue;
       if (sz[v] > mx) mx = sz[v], bigchild = v;
    }
    for (auto v : g[u]) {
      if (v == p || v == bigchild) continue;
      dsu(v, u, 0);
    }
    if (bigchild != -1) dsu(bigchild, u, 1), big[bigchild] = 1;
    add(u, p, 1);
    ans[u] = sum;
    if (bigchild != -1) big[bigchild] = 0;
    if (keep == 0) add(u, p, -1), mxcnt = 0 , sum = 0;
}
void solve(int cs){
    int n; cin >> n;
    set<int>s;
    for(int i = 1; i <= n; i++){
        cin >> col[i];
        s.insert(col[i]);
    }
    int id = 1;
    map<int,int>mp;
    for(auto u : s)mp[u] = id++;
    for(int i = 1; i <= n; i++)col[i] = mp[col[i]];
    
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    dsu(1,-1,1);
    for(int i = 1; i <= n; i++)cout << ans[i] << " "; cout << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, cs = 1;
    //cin >> t;
    while(t--){
        solve(cs++);
    }
    return 0;
}