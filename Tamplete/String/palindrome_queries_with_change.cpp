#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl '\n'
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
const int N = 2e5+5;
 
std::vector<pair<int,int>> pw(N),inv(N);
 
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
 
struct{
	pair<int,int>pref[N*4];
	void build(int n, int l, int r,string& s){
		if(l == r){
	        pref[n].first = s[l] * 1ll * pw[l].first % mod1;
	        pref[n].second = s[l] * 1ll * pw[l].second % mod2;
	        return;
    	}
	    int mid = (l+r)>>1;
	    build(n*2, l, mid,s);
	    build(n*2+1, mid+1, r,s);
	    pref[n].first = (pref[n*2].first + pref[n*2 + 1].first) % mod1;
	    pref[n].second = (pref[n*2].second + pref[n*2 + 1].second) % mod2;
	}
	void upd(int n,int l, int r, int b,int val){
	    if (l > b || r < b) return;
	    if(l == r and l == b){
	        pref[n].first = val * 1ll * pw[l].first % mod1;
	        pref[n].second = val * 1ll * pw[l].second % mod2;
	        return;
    	}
	    int mid = (l+r)>>1;
	    if(b <= mid )upd(n*2,l,mid,b,val);
	    else upd(n*2+1,mid+1,r,b,val);
	    pref[n].first = (pref[n*2].first + pref[n*2 + 1].first) % mod1;
	    pref[n].second = (pref[n*2].second + pref[n*2 + 1].second) % mod2;
	}
 
	pair<int,int> query(int node,int l, int r, int b, int e){
	    if(r < b or e < l)return {0,0};
	    if(b <= l and r <= e)return pref[node];
	    int mid = (l+r)>>1;
	    auto q = query(node*2,l,mid,b,e);
	    auto p = query(node*2+1,mid+1,r,b,e);
	    return {(q.first+p.first)%mod1 ,(q.second+p.second)%mod2};
	}
	
}A,B;
 
 
 
void solve(int cs){
	int n,q; cin >> n >> q;
    string a,b;
    cin>>a;
    b = a;
    reverse(b.begin(),b.end());
    A.build(1,0,n-1,a);
    B.build(1,0,n-1,b);
 
    while(q--){
    	int t; cin >> t;
    	if(t == 1){
    		int i;
    		char x;
    		cin>> i >> x;
    		A.upd(1,0,n-1,i-1,x);
    		B.upd(1,0,n-1,(n-i),x);
    	}else{
    		int i,j; cin >> i >> j;
    		i--;
    		j--;
    		int x = n - j - 1, y = n - i - 1;
    		auto p = A.query(1,0,n-1,i,j);
    		auto q = B.query(1,0,n-1,x,y);
    		p.first = p.first * 1ll * inv[i].first % mod1;
    		p.second = p.second * 1ll * inv[i].second % mod2;
    		
    		q.first = q.first * 1ll * inv[x].first % mod1;
    		q.second = q.second * 1ll * inv[x].second % mod2;
    		if( p == q ){
    			cout<<"YES"<<endl;
    		}else cout<<"NO"<<endl;
    	}
    }
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