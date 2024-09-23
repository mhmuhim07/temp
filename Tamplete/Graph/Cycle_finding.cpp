#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e5+5;
std::vector<int> g[N],p(N),col(N),vis(N);
int start,ok = 0;
vector<int>ans;
void dfs(int s,int pr) {
    if(ok)return;
    vis[s] = 1;
    p[s] = pr;
    col[s] = 1;

    for(auto u:g[s]) {
        if(ok)return;
        if(!vis[u]) {
            dfs(u,s);
        } else {
            if(col[u]) {
                ok = 1;
                int st = s;
                while(st != u) {
                    ans.push_back(st);
                    st = p[st];

                }
                ans.push_back(u);
                ans.push_back(s);
                return;
            }
        }
    }
    col[s] = 0;
}
void solve(int cs) {
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) {

        if(vis[i] == 0) {
            dfs(i,0);
            if(ok) {
                cout<<ans.size()<<endl;
                reverse(ans.begin(),ans.end());
                for(auto i:ans)cout<<i<<" ";
                cout<<endl;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1,cs=0;
    //cin >> t;
    while(t--)
    {
        solve(++cs);
    }

    return 0;
}
