#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200005;
const int LOG = 20;
const ll MOD = 1000000007;

vector<int> adj[MAXN];
int parent[MAXN][LOG];
int depth[MAXN];
int tin[MAXN], tout[MAXN];
int timer = 0;
int n, q;

void dfs(int u, int p) {
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
            dfs(v, u);
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
ll solve_query_efficient(vector<int>& nodes) {
    int k = nodes.size();
    if (k < 2) return 0;
    
    // Mark which nodes are in the set
    vector<bool> in_set(n+1, false);
    for (int u : nodes) {
        in_set[u] = true;
    }
    sort(nodes.begin(), nodes.end(), [](int u, int v) {
        return tin[u] < tin[v];
    });
    
    // Add LCAs
    for (int i = 0; i < k-1; i++) {
        int l = lca(nodes[i], nodes[i+1]);
        if (!in_set[l]) {
            nodes.push_back(l);
            in_set[l] = true;
        }
    }
    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
    sort(nodes.begin(), nodes.end(), [](int u, int v) {
        return tin[u] < tin[v];
    });
    stack<int> st;
    vector<pair<int, int>> virtual_edges;
    vector<int> virtual_adj[MAXN];
    
    for (int u : nodes) {
        while (!st.empty()) {
            int v = st.top();
            if (is_ancestor(v, u)) {
                virtual_adj[v].push_back(u);
                virtual_adj[u].push_back(v);
                virtual_edges.push_back({v, u});
                break;
            }
            st.pop();
        }
        st.push(u);
    }
    
    ll ans = 0;
    for (int i = 0; i < nodes.size(); i++) {
        for (int j = i+1; j < nodes.size(); j++) {
            int u = nodes[i], v = nodes[j];
            if (u > n || v > n) continue;
            if (u > v) swap(u, v);
            ll d = dist(u, v);
            ans = (ans + (1LL * u * v % MOD) * d % MOD) % MOD;
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;
    
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
    dfs(1, -1);
    
    while (q--) {
        int k;
        cin >> k;
        vector<int> nodes(k);
        for (int i = 0; i < k; i++) {
            cin >> nodes[i];
        }
        
        cout << solve_query_efficient(nodes) << "\n";
    }
    
    return 0;
}