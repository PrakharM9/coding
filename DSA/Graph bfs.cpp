#include<bits/stdc++.h>
using namespace std;
vector<int>bfsGraph(int V,vector<int>adj[]){
    int vis[V]={0};
    vis[0]=1;
    vector<int>bfs;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[m+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>bfs=bfsGraph(n,adj);
    for(int it:bfs){
        cout<<it<<" ";
    }
    return 0;
}