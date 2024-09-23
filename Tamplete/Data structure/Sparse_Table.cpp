#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
const int K = 19;
int a[N];
pair<int,int>st[N][K];

void build(int n) {
	for (int i = 0; i < n; i++){
		st[i][0].first = st[i][0].second = a[i];
	} 
	for (int j = 1; j < K; j++) {
		for (int i = 0; i < n; i++) {
			if (i + (1 << j) > n) continue;
			st[i][j].first = max(st[i][j - 1].first, st[i + (1 << j - 1)][j - 1].first);
			st[i][j].second = min(st[i][j - 1].second, st[i + (1 << j - 1)][j - 1].second);
		}
	}
}
pair<int,int> query(int l, int r) {
	int x = 31 - __builtin_clz(r - l + 1);
	int mx = max(st[l][x].first, st[r - (1 << x) + 1][x].first);
	int mn = min(st[l][x].second, st[r - (1 << x) + 1][x].second);
	return {mx,mn};
}
int main() {
	int t ,cs = 1;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(st,0,sizeof(st));
		int n,d;
		cin >> n>>d;
		for (int i = 0; i < n; i++) cin >> a[i];
		build(n);
		int ans = 0;
		for(int i = d-1; i < n; i++){
			pair<int,int>tm = query((i-d+1),i);
			//cout<<(i-d+1)<<" "<<i<<" ";
			//cout<<tm.first<<" "<<tm.second<<endl;
			ans = max(ans,(tm.first - tm.second));
		}
		cout<<"Case "<<cs++<<": "<<ans<<'\n';
	}
	
	return 0;
}