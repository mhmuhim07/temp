#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vl vector<ll>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define ll long long
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

void solve()
{
    int n;
    cout<<"Enter the number of item: ";
    cin>>n;

    cout<<"Enter the capacity: ";
    int c;
    cin>>c;

    int p[n],w[n];
    cout<<"Enter items price: ";
    fo(i,0,n)cin>>p[i];

    cout<<"Enter items weight: ";
    fo(i,0,n)cin>>w[i];

    int a[n+1][c+1];
    memset(a,0,sizeof(a));

    for(int i = 1;i<=n;i++){

           for(int j = 1;j<=c;j++){
              if(j>=w[i-1]){
                a[i][j]=max(a[i-1][j],((a[i-1][j-w[i-1]])+p[i-1]));
                }

              else{
               a[i][j]=a[i-1][j];
               }

             }

    }
    

    cout<<"Total profite: "<<a[n][c]<<endl;
 
}
int main()
{

    fast;

    int t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
