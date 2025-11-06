#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG = 17;

struct Node {
    int l, r, sum;
} seg[40 * MAXN];

int n, m, a[MAXN], root[MAXN], tot;
vector<int> g[MAXN];
int up[LOG + 1][MAXN], depth[MAXN];
vector<int> sorted_vals;

int update(int prev, int l, int r, int pos) {
    int cur = ++tot;
    seg[cur] = seg[prev];
    seg[cur].sum++;
    if (l == r) return cur;
    int mid = (l + r) >> 1;
    if (pos <= mid) 
        seg[cur].l = update(seg[prev].l, l, mid, pos);
    else 
        seg[cur].r = update(seg[prev].r, mid + 1, r, pos);
    return cur;
}

void dfs(int u, int p) {
    up[0][u] = p;
    for (int i = 1; i <= LOG; i++)
        up[i][u] = up[i - 1][up[i - 1][u]];
    
    root[u] = update(root[p], 1, sorted_vals.size(), a[u]);
    
    for (int v : g[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    
    for (int i = LOG; i >= 0; i--)
        if (diff & (1 << i)) 
            u = up[i][u];
    
    if (u == v) return u;
    
    for (int i = LOG; i >= 0; i--)
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    
    return up[0][u];
}

int query(int ru, int rv, int rl, int rpl, int l, int r, int k) {
    if (l == r) return l;
    
    int leftCount = seg[seg[ru].l].sum + seg[seg[rv].l].sum
                    - seg[seg[rl].l].sum - seg[seg[rpl].l].sum;
    
    int mid = (l + r) >> 1;
    
    if (k <= leftCount)
        return query(seg[ru].l, seg[rv].l, seg[rl].l, seg[rpl].l, l, mid, k);
    else
        return query(seg[ru].r, seg[rv].r, seg[rl].r, seg[rpl].r, mid + 1, r, k - leftCount);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    vector<int> vals(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vals[i];
    }
    sorted_vals = vector<int>(vals.begin() + 1, vals.end());
    sort(sorted_vals.begin(), sorted_vals.end());
    sorted_vals.erase(unique(sorted_vals.begin(), sorted_vals.end()), sorted_vals.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(sorted_vals.begin(), sorted_vals.end(), vals[i]) - sorted_vals.begin() + 1;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    depth[1] = 0;
    dfs(1, 0);
    
    for (int i = 0; i < m; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        
        int L = lca(u, v);
        int pL = up[0][L];
        
        int pos = query(root[u], root[v], root[L], root[pL], 1, sorted_vals.size(), k);
        
        cout << sorted_vals[pos - 1] << "\n";
    }
    
    return 0;
}