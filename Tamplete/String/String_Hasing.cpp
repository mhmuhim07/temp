#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
const int N = 1e5+5;

std::vector<pair<int,int>> pref(N),pw(N),inv(N);

int power(ll n, ll k, int mod) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (ll) ans * n % mod;
    n = (ll) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int invp1,invp2;
void pre(){
	pw[0] = {1,1};
	for(int i = 1; i < N; i++){
		pw[i].first = p1 * 1ll * pw[i-1].first % mod1;
		pw[i].second = p2 * 1ll * pw[i-1].second % mod2; 
	}
	invp1 = power(p1, mod1 - 2, mod1);
	invp2 = power(p2, mod2 - 2, mod2);
	inv[0] = {1,1};
	for(int i = 1; i < N; i++){
		inv[i].first = invp1  * 1ll * inv[i-1].first % mod1;
		inv[i].second = invp2  * 1ll * inv[i-1].second % mod2;
	}
}

pair<int,int>string_hash(string s){
	int n = s.size();
	pair<int,int>ans = {0,0};

	for(int i = 0; i < n; i++){
		ans.first += pw[i].first * 1ll * s[i] % mod1;
		ans.first %= mod1;

		ans.second += pw[i].second * 1ll * s[i] % mod2;
		ans.second %= mod2; 
	}
	return ans;
}

void build(string s){
	int n = s.size();
	for(int i = 0; i < n; i++){
		pref[i].first = pw[i].first * 1ll * s[i] % mod1;
		if(i)pref[i].first = (pref[i].first + pref[i-1].first)%mod1;

		pref[i].second = pw[i].second * 1ll * s[i] % mod2;
		if(i)pref[i].second = (pref[i].second + pref[i-1].second)%mod2;
	}
}

pair<int,int> get_hash(int i, int j){
	assert(i <= j);
	pair<int,int>ans = {0,0};
	ans.first = pref[j].first;
	if(i)ans.first = (ans.first - pref[i-1].first + mod1) % mod1;
	ans.first = ans.first * 1ll * inv[i].first % mod1;

	ans.second = pref[j].second;
	if(i)ans.second = (ans.second - pref[i-1].second + mod2) % mod2;
	ans.second = ans.second * 1ll * inv[i].second % mod2;
	return ans;
}
int lcp(int i, int j,int x,int y){
	int l = 1, r = min(j - i + 1, y - x + 1),ans = 0;
	while(l <= r){
		int mid = (l + r) >> 1;
		auto t = get_hash(i,i+mid-1);
		auto tt = get_hash(x,x+mid-1);
		if(t == tt){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	return ans;
}
void solve(int cs){
    string a,b;
    cin>>a>>b;
    cout<<(string_hash(a) == string_hash(b))<<endl;
}
   
int main()
{

    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=1,cs=0;
    //cin >> t;
    pre();
    while(t--)
    {
        solve(++cs);
    }

    return 0;
}