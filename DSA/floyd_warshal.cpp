#include<bits/stdc++.h>
using namespace std;
void addedge(int adj[][100],int u,int v){
	adj[u][v] = 1;
	adj[v][u] = 1;
}
bool bfs(int adj[][100],int src,int dest,int node,int pred[],int dist[]){
	queue<int>q;
	vector<bool> visited(node,false);
	for(int i=0;i<node;i++){
		dist[i] = INT_MAX;
		pred[i] = -1;
	}
	visited[src] = true;
	dist[src] = 0;
	q.push(src);
	while(!q.empty()){
		int u  = q.front();
		q.pop();
		for(int i=0;i<node;i++){
			if(adj[u][i] == 1 && !visited[i]){
				visited[i] = true;
				dist[i] = dist[u]+1;
				pred[i] = u;
				q.push(i);
				if(i==dest){
					return true;
				}1
			}
		}
	}
	return false;
}
void printShortestDistance(int adj[][100], int s, int dest, int v, int pred[], int dist[]) {
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    cout << "Shortest path length is : " << dist[dest] << "\nPath is : ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}
int main() {
	int node ,edge;
	cin>>node>>edge;
	int adj[100][100] = {0};
	for(int i=0;i<edge;i++){
		int u,v;
		addedge(adj,u,v);
	}
	int source,dest;
	cin>>source>>dest;
	int predecessor[node],distance[node];
	if(bfs(adj,source,dest,node,predecessor,distance)){
		printShortestDistance(adj,source,dest,node,predecessor,distance);
	}
}