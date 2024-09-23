#include<bits/stdc++.h>
#define sz 200005
const int N = 2000007;
using namespace std;
vector<int>adj[sz],cost[sz];
bool vis[sz];

priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;


int prims(int st)
{
    for(int i=0; i<adj[st].size(); i++)
        pq.push({cost[st][i],{st,adj[st][i]}});

    vector<pair<int,pair<int,int> > >ans;
    vis[st]=1;
    int c,u,v,tot=0;
    while(!pq.empty())
    {
        c=pq.top().first;
        u=pq.top().second.first;
        v=pq.top().second.second;
        pq.pop();
        if(vis[u]==false||vis[v]==false)
        {
            ans.push_back({c,{u,v}});
            tot+=c;
            if(vis[u]==1)
                u=v;
            else u=u;
            vis[u]=1;
            for(int i=0; i<adj[u].size(); i++)
            {
                if(vis[adj[u][i]]==false)
                    pq.push({cost[u][i],{u,adj[u][i]}});

            }
        }
    }
    for(int i=0;i<ans.size();i++)
    {
       cout<<i+1<<":"<<ans[i].first<<" -> ("<<ans[i].second.first<<","<<ans[i].second.second<<")"<<endl;
    }
    return tot;
}
int main()
{
    int st,n,m,x,y,z;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>z;
        adj[x].push_back(y);
        cost[x].push_back(z);
        adj[y].push_back(x);
        cost[y].push_back(z);
    }
    cin>>st;
    cout<<"Total cost of MST="<<prims(st)<<endl;
    return 0;
}