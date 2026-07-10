#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;
 
struct DSU {
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) parent[rx] = ry;
        else if (rank[rx] > rank[ry]) parent[ry] = rx;
        else {
            parent[ry] = rx;
            rank[rx]++;
        }
        return true;
    }
};
 
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w > other.w;
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--; edges[i].v--;
    }
    
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    vector<vector<pair<int, int>>> mst(n);
    
    
    for (const auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst[e.u].push_back({e.v, e.w});
            mst[e.v].push_back({e.u, e.w});
        }
    }
    
   
    vector<int> result(n, 0);
    result[s] = -1;
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (auto [to, w] : mst[v]) {
            if (!visited[to]) {
                visited[to] = true;
                if (v == s) result[to] = w;
                else result[to] = min(result[v], w);
                q.push(to);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
    
    return 0;
}