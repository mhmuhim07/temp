#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int N = 2e5 + 5,LOG = 20;
std::vector<int> g[N];
int up[N][LOG],dept[N];

void dfs(int s,int p){
	for(auto u : g[s]){
		if(u == p)continue;

		dept[u] = dept[s] + 1;
		up[u][0] = s;
		for(int j = 1; j < LOG; j++){
			up[u][j] = up[up[u][j-1]][j-1];
		}
		dfs(u,s);
	}
}

int LCA(int a, int b){
	if(dept[a] < dept[b])swap(a,b);
	int k = dept[a] - dept[b];
	for(int j = LOG - 1; j >= 0; j--){
		if(k & (1 << j)) a = up[a][j];
	}
	if(a == b) return a;
	for(int j = LOG - 1; j >= 0; --j){
		if(up[a][j] != up[b][j]){
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}

int Kth_ancestor(int a,int k){
	if(k > dept[a]) return -1;
	for(int j = LOG - 1; j >= 0; j--) {
         if(k >= (1 << j)) {
            a = up[a][j];
            k -= 1 << j;
        }
    }
	return a;
}

void solve(int cs){
    int n,m; cin >> n >> m;
    for(int a = 2; a <= n; a++){
    	
    	int b; cin >> b;
    	g[b].push_back(a);
    }
    dfs(1,-1);
    while(m--){
    	int a,b; cin >> a >> b;
    	cout << LCA(a,b) << endl;
    	cout << Kth_ancestor(a,b) << endl;
    }
}
   
int main()
{

    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=1,cs=0;
    //cin >> t;
    while(t--)
    {
        solve(++cs);
    }

    return 0;
}
