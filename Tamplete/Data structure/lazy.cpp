#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 3e5 + 9;

int a[N];
struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) + 1)
  long long t[4 * N], lazy[4 * N];
  ST() {
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void push(int n, int b, int e) { // change this
    if (lazy[n] == 0) return;
    t[n] = t[n] + lazy[n] * (e - b + 1);
    if (b != e) {
      lazy[lc] = lazy[lc] + lazy[n];
      lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a,long long b) { // change this
    return a + b;
  }
  inline void pull(int n) { // change this
    t[n] = t[lc] + t[rc];
  }
  void build(int n, int b, int e) {
    lazy[n] = 0; // change this
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] = v; //set lazy
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
}t;

void solve(int cs){
    
    int n = 5;
    for (int i = 1; i <= n; i++) {
      a[i] = i;
    }
    t.build(1, 1, n); // building the segment tree
    t.upd(1, 1, n, 2, 10); // assiging 10 to the index 2 (a[2] := 10)
    cout << t.query(1, 1, n, 1, 5) << '\n'; // range max query on the segment [1, 5]
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, cs = 0;
    //cin >> t;
    while(t--){
        solve(++cs);
    }
    return 0;
}