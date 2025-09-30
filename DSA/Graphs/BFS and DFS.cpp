#include<bits/stdc++.h>
using namespace std;
void addedge(int adj[][100],int u,int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}
void print(int adj[][100],int node){
    for(int i=0;i<node;i++){
        cout<<i<<" -> ";
        for(int j = 0;j<node;j++){
            if(adj[i][j]==1){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
}
void bfs(int adj[][100],int start,int n){
    vector<bool>visited(n,false);
    queue<int>q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int u  = q.front();
        q.pop();
        cout<<u<<" ";
        for(int i = 0;i<n;i++){
            if(adj[u][i] == 1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        } 
    }
    cout<<endl;
}
void dfs2(int adj[][100],int node,bool visited[],int n){
    visited[node] = true;
    cout<<node<<" ";
    for(int i=0;i<n;i++){
        if(adj[node][i] == 1 && !visited[i]){
            dfs2(adj,i,visited,n);
        }
    }

}
void dfs(int adj[][100],int start,int n){
    bool visited[100] = {false};
    dfs2(adj,start,visited,n);
}
int main() {
    int node,edge;
    cin>>node>>edge;
    int adj[100][100] = {0};
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        addedge(adj,u,v);
    }
    cout<<"Matrix: "<<endl;
    print(adj,node);
    cout<<"Bfs: ";
    bfs(adj,0,node);
    cout<<endl;
    cout<<"Dfs: ";
    dfs(adj,0,node);

}