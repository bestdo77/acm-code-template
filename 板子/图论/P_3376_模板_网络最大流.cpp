#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>

using namespace std;

const int INF = 1e9;
#define int long long
struct Edge {
    int to;
    int cap;
    int rev;
    bool is_rev;
    Edge(int t, int c, int r, bool rev_edge) : to(t), cap(c), rev(r), is_rev(rev_edge) {}
};

class Graph {
public:
    vector<vector<Edge>> adj;
    vector<int> level;
    vector<int> ptr;
    int n;
    bitset<100005> used; // 假设节点数不超过100005

    Graph(int _n) : n(_n), adj(_n), level(_n), ptr(_n) {}

    void add_edge(int from, int to, int cap) {
        adj[from].push_back(Edge(to, cap, adj[to].size(), false));
        adj[to].push_back(Edge(from, 0, adj[from].size()-1, true));
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            used.reset();
            int pushed;
            while ((pushed = dfs(s, t, INF)) > 0) {
                flow += pushed;
            }
        }
        return flow;
    }

private:
    bool bfs(int s, int t) {
        queue<int> q;
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (const Edge& e : adj[v]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                    if (e.to == t) return true;
                }
            }
        }
        return false;
    }

    int dfs(int v, int t, int pushed) {
        if (v == t) return pushed;
        used.set(v);
        for (int& i = ptr[v]; i < adj[v].size(); ++i) {
            Edge& e = adj[v][i];
            if (!used[e.to] && e.cap > 0 && level[v] < level[e.to]) {
                int tr = dfs(e.to, t, min(pushed, e.cap));
                if (tr > 0) {
                    e.cap -= tr;
                    adj[e.to][e.rev].cap += tr;
                    return tr;
                }
            }
        }
        return 0;
    }
};

signed main() {
    int n,m;cin>>n>>m;
    int s=1,t=m;
    Graph g(m+1);
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g.add_edge(u, v, w);
    }

    int flow=g.max_flow(s, t);
    cout << g.max_flow(s, t) << " "<< endl;

    return 0;
}