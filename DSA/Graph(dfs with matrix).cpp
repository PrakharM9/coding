#include <iostream>
using namespace std;
#define MAX_VERTICES 100
void addEdge(int adj[MAX_VERTICES][MAX_VERTICES], int v, int w) {
    //Type your code
    adj[v][w]=1;
}

void DFS(int adj[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int V, int v) {
    //Type your code
    visited[v]=1;
    cout<<v<<" ";
    for(int i=0;i<V;i++){
        if(!visited[i] && adj[v][i]==1){
            DFS(adj,visited,V,i);
        }
    }
}
int main() {
    int V, E;
    cin >> V;
    cin >> E;

    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        addEdge(adj, v, w);
    }

    int startVertex;
    cin >> startVertex;

    cout << "Depth First Traversal starting from vertex " << startVertex << ":\n";
    DFS(adj, visited, V, startVertex);

    return 0;
}