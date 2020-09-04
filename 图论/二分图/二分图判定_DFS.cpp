#include <bits/stdc++.h>

using namespace std;

constexpr size_t kMaxV = 1e5 + 5;

struct Edge { int u, v; };

class Graph {
  public:
    vector<int> adj_[kMaxV];
    vector<Edge> e_;

    void init() {
        e_.clear();
        for (auto& i: adj_)
            i.clear();
    }

    void addEdge(int u, int v) {
        adj_[u].push_back(e_.size());
        e_.push_back({u, v});
    }
};

bool vis[kMaxV];
int color[kMaxV];

bool dfs(int u, const Graph& g) {
    vis[u] = true;
    for (const auto& i: g.adj_[u]) {
        int v = g.e_[i].v;
        if (!vis[v]) {
            color[v] = 1 - color[u];
            if (!dfs(v, g)) return false;
        } else if (color[u] == color[v]) {
            return false;
        }
    }
    return true;
}

bool isBG(const Graph& g) {
    memset(vis, 0, sizeof(vis));
    memset(color, 0, sizeof(color));
    for (int i = 0; i < kMaxV; ++i) {
        if (!vis[i] && g.adj_[i].size() > 0) {
            if (!dfs(i, g)) return false;
        }
    }
    return true;
}

int main() {

    return 0;
}