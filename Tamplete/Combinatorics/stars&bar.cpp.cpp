#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int N = 2e6+3, mod = 1e9+7;
int f[N],invf[N];
int power(int a,int b){
	int ans = 1;
	while(b){
		if(b%2)ans = ans * 1ll * a % mod;
		b /= 2;
		a = a * 1ll * a % mod;
	}
	return ans;
}
int nCr(int n, int r){
	if(n < r or n < 0)return 0;
	return f[n] *1ll* invf[r] % mod * invf[n-r] % mod;
}
void solve(int cs){
	int n,r;
    cin >> n >> r;
    ///cout<<f[n] <<" "<< invf[r] <<" "<<invf[n-r]<<endl;
    cout <<"Case "<<cs<<": "<<nCr(n+r-1,r-1)<<endl;//with values equal zero
    cout <<"Case "<<cs<<": "<<nCr(n-1,r-1)<<endl;//with values greater than zero

}
   
int main()
{

    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=1,cs=0;
    f[0]=1;
	for(int i = 1; i < N; i++){
		f[i] = f[i-1] * 1ll * i % mod;
	}
	invf[N-1] = power(f[N-1],mod-2);
	for(int i = N - 2; i >= 0; --i){
		invf[i] = invf[i+1] *1ll* (i+1) % mod;
	}
    cin >> t;
    while(t--)
    {
        solve(++cs);
    }

    return 0;
}
