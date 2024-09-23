#include<bits/stdc++.h>
#define sz 200005
using namespace std;
vector<pair<int,int>>adj[sz];
int n,m;
void djkstra(int st)
{
    vector<int> dist(n+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> >  >pq;
    pq.push({0,st});
    dist[st]=0;
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(int i = 0; i<adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(dist[u]+w<dist[v]) {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    cout<<"Vertex Distance from Source: "<<endl;
    for(int i = 0; i<n; i++) {
        cout<<i<<"->"<<dist[i]<<endl;
    }

}
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});

    }
    int st;
    cin>>st;
    djkstra(st);

    return 0;
}