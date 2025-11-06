#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int LOG = 20;
int N, A[200005], up[LOG][200005], depth[200005], tin[200005], tout[200005], timer;
vector<int> g[200005];

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[0][v] = p;
    for (int i = 1; i < LOG; i++)
        up[i][v] = up[i - 1][up[i - 1][v]];
    for (int to : g[v]) if (to != p) {
        depth[to] = depth[v] + 1;
        dfs(to, v);
    }
    tout[v] = ++timer;
}

inline bool is_ancestor(int u, int v) { 
    return tin[u] <= tin[v] && tout[v] <= tout[u]; 
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = LOG - 1; i >= 0; i--)
        if (!is_ancestor(up[i][u], v)) u = up[i][u];
    return up[0][u];
}

inline int dist(int u, int v) { 
    return depth[u] + depth[v] - 2 * depth[lca(u, v)]; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0, u, v; i < N - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) cin >> A[i];
    
    dfs(1, 1);
    vector<vector<int>> nodes(N + 1);
    for (int i = 1; i <= N; i++) {
        nodes[A[i]].push_back(i);
    }

    ll ans = 0;
    vector<vector<pair<int,int>>> vt(N + 1);

    for (int val = 1; val <= N; val++) {
        auto &v = nodes[val];
        if (v.size() <= 1) continue;
        sort(v.begin(), v.end(), [&](int a, int b){ return tin[a] < tin[b]; });
        vector<int> vs = v;
        for (int i = 1; i < (int)v.size(); i++) {
            vs.push_back(lca(v[i - 1], v[i]));
        }
        sort(vs.begin(), vs.end(), [&](int a, int b){ return tin[a] < tin[b]; });
        vs.erase(unique(vs.begin(), vs.end()), vs.end());

        vector<int> st;
        for (int x : vs) {
            while (!st.empty() && !is_ancestor(st.back(), x)) {
                st.pop_back();
            }
            if (!st.empty()) {
                int p = st.back();
                int d = dist(p, x);
                vt[p].push_back({x, d});
                vt[x].push_back({p, d});
            }
            st.push_back(x);
        }

        function<int(int,int)> dfs2 = [&](int u, int p) {
            int cnt = count(v.begin(), v.end(), u);
            for (auto [to, w] : vt[u]) {
                if (to != p) {
                    int sub = dfs2(to, u);
                    ans += 1LL * w * sub * ((int)v.size() - sub);
                    cnt += sub;
                }
            }
            return cnt;
        };
        
        dfs2(vs[0], 0);
        for (int x : vs) vt[x].clear();
    }

    cout << ans << "\n";
    return 0;
}