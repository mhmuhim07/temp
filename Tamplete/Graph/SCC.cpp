#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5+5;
std::vector<int>gp[N],rgp[N],grp[N];

bool vis[N];

void dfs(int s, stack<int>&st){
    vis[s] = 1;
    for(auto u:gp[s]){
        if(!vis[u]){
            dfs(u,st);
        }
    }
    st.push(s);
}
void dfs1(int s, vector<int>&v){
    vis[s] = 1;
    v.push_back(s);
    for(auto u:rgp[s]){
        if(!vis[u])dfs1(u,v);
    }
}
void solve(int cs){
    
    int n,m;
    cin>>n>>m;
    
    for(int i = 0; i < m; i++){
        int a,b;cin>>a>>b;
        gp[a].push_back(b);
        rgp[b].push_back(a);
    }
    stack<int>st;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i,st);
        }
    }
    memset(vis, 0 , sizeof vis);
    int scc = 0;
    while(!st.empty()){
        int i = st.top();
        st.pop();
        if(!vis[i]){
            vector<int>v;
            dfs1(i,v);
            for(auto u:v)grp[scc].push_back(u);
            scc++;
        }
    }
    cout << "Number of SCC " << scc << endl;
    for(int i = 0; i < scc; i++){
        for(auto u:grp[i])cout << u << " "; cout << endl;
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