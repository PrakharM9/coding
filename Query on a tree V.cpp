#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG = 17;
const int INF = 1e9;

vector<int> adj[MAXN];
int parent[MAXN][LOG];
int depth[MAXN];
int sz[MAXN];
bool white[MAXN];
int n;
int timer = 0;
int tin[MAXN], tout[MAXN];

void dfs_lca(int u, int p) {
    tin[u] = timer++;
    parent[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        if (parent[u][i-1] != -1)
            parent[u][i] = parent[parent[u][i-1]][i-1];
        else
            parent[u][i] = -1;
    }
    
    for (int v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs_lca(v, u);
        }
    }
    tout[u] = timer++;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    
    for (int i = LOG-1; i >= 0; i--) {
        if (parent[u][i] != -1 && !is_ancestor(parent[u][i], v)) {
            u = parent[u][i];
        }
    }
    return parent[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
bool removed[MAXN];
int par_centroid[MAXN];
vector<int> centroid_adj[MAXN];
multiset<int> best_dist[MAXN]; 

void dfs_size(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p && !removed[v]) {
            dfs_size(v, u);
            sz[u] += sz[v];
        }
    }
}

int find_centroid(int u, int p, int total) {
    for (int v : adj[u]) {
        if (v != p && !removed[v] && sz[v] > total/2) {
            return find_centroid(v, u, total);
        }
    }
    return u;
}

void decompose(int u, int p) {
    dfs_size(u, -1);
    int centroid = find_centroid(u, -1, sz[u]);
    
    removed[centroid] = true;
    par_centroid[centroid] = p;
    if (p != -1) {
        centroid_adj[p].push_back(centroid);
    }
    
    for (int v : adj[centroid]) {
        if (!removed[v]) {
            decompose(v, centroid);
        }
    }
}
void update(int node) {
    int curr = node;
    while (curr != -1) {
        int d = dist(curr, node);
        
        if (white[node]) {
            best_dist[curr].insert(d);
        } else {
            auto it = best_dist[curr].find(d);
            if (it != best_dist[curr].end()) {
                best_dist[curr].erase(it);
            }
        }
        curr = par_centroid[curr];
    }
    white[node] = !white[node];
}

int query(int node) {
    if (white[node]) return 0;
    
    int result = INF;
    int curr = node;
    
    while (curr != -1) {
        if (!best_dist[curr].empty()) {
            int d = dist(curr, node);
            result = min(result, d + *best_dist[curr].begin());
        }
        curr = par_centroid[curr];
    }
    
    return result == INF ? -1 : result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < LOG; j++) {
            parent[i][j] = -1;
        }
    }
    depth[1] = 0;
    dfs_lca(1, -1);
    for (int i = 1; i <= n; i++) {
        removed[i] = false;
        white[i] = false;
    }
    decompose(1, -1);
    
    int q;
    cin >> q;
    
    while (q--) {
        int type, x;
        cin >> type >> x;
        
        if (type == 0) {
            update(x);
        } else {
            cout << query(x) << "\n";
        }
    }
    
    return 0;
}