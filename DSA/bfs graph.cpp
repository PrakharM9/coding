#include <bits/stdc++.h>
using namespace std;
vector<int>bfsGraph(int V,vector<int>adj[]){
    int vis[V]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
    }
}
int main()
{
  
  return 0;
}