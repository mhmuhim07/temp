
#include<bits/stdc++.h>
using namespace std;

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define ll long long
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);

int dx[] = {1,-1,0,0,-1,-1,1,1};
int dy[] = {0,0,1,-1,-1,1,1,-1};
const ll M = 100000007;
ll dp[55][10005];
int n,k;

ll fnc(int idx,int amount,vector<int>& coins,vector<int>& ocr) {
    if(amount == 0 )return 1;
    if(idx<0) return 0;
    if(dp[idx][amount]!=-1)return dp[idx][amount];

    ll ways = 0;
    int j = 0;
    for(int i = 0; (i<=amount&& j<=ocr[idx]); i+=coins[idx]) {
        j++;
        ways+= fnc(idx-1,amount-i,coins,ocr)%M;
    }
    return dp[idx][amount]=ways%M;

}
void solve(int cs) {
    cin>>n>>k;
    std::vector<int>coins(n),ocr(n);
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i<n; i++)cin>>coins[i];
    for(int i = 0; i<n; i++)cin>>ocr[i];
    cout<<"Case "<<cs<<": "<<fnc(n-1,k,coins,ocr)%M<<endl;
}

int main()
{

    fast;
    int t=1,cs=0;
    cin >> t;
    while(t--)
    {
        solve(++cs);
    }

    return 0;
}
