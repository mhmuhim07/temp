#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e5+5;
vector<int>g[N];
void solve(int cs){
    int n,m;cin>>n>>m;
    std::vector<int> in(n+1),ans,t;
    memset(g,0,sizeof g);
    for(int i = 0; i < m; i++){
    	int a,b;cin>>a>>b;
    	g[a].push_back(b);
    	in[b]++;
    }
    for(int i = 1; i <= n; i++){
    	if(in[i] == 0)t.push_back(i);
    }
    while(t.size() != 0){
    	int cur = t.back();
    	t.pop_back();
    	bool ok = 0;
    	for(auto u:g[cur]){
    		in[u]--;
    		if(!in[u]){
    		    ok = 1;
    		    t.push_back(u);
    		}
    	}
    	ans.push_back(cur);
    }
    if(ans.size() < n){
        cout<<"IMPOSSIBLE\n";
    	return;
    }
    for(auto u:ans)cout<<u<<" ";cout<<endl;
}
   
int main()
{

    ios_base::sync_with_stdio(false);cin.tie(0);
    int t=1,cs=0;
    
    while(t--)
    {
        solve(++cs);
    }

    return 0;
}
