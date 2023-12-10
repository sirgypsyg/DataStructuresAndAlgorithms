#include <iostream>
#include <vector>
#include <utility>
#include <set>

#define inf INT_MAX
#define pair std::pair<int,int>

struct G {
    std::vector<pair> adj;
    std::vector<int> occupiedAtMin;
    int dist = inf;
} *node;

void dijkstra(int start) {
    int curDist, a, b;
    node[start].dist = 0;

    std::set<pair> edges;

    edges.insert(std::make_pair(0, start));

    while (!edges.empty()) {
        curDist = edges.begin()->first;
        b = edges.begin()->second;
        node[b].dist = std::min(curDist, node[b].dist);
        if (b == 0) {
            std::cout << node[b].dist << "\n";
            return;
        }

        edges.erase(edges.begin());

        for (int i = 0; i < node[b].adj.size(); i++) {
            if (node[node[b].adj[i].first].dist == inf) {
                int plusDist = node[b].adj[i].second + curDist;
                if (!node[node[b].adj[i].first].occupiedAtMin.empty()) {
                    int size = node[node[b].adj[i].first].occupiedAtMin.size();
                    int it = 0;
                    while (size - it > 0) {
                        if (node[node[b].adj[i].first].occupiedAtMin[it] == plusDist)
                            ++plusDist;
                        ++it;
                    }
                }
                edges.insert(std::make_pair(plusDist, node[b].adj[i].first));
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int d, n, m, s;

    std::cin >> d;

    for (int i = 0; i < d; ++i) {
        std::cin >> n >> m >> s;
        node = new G[n];

        for (int j = 0; j < m; ++j) {
            int x, y, w;
            std::cin >> x >> y >> w;
            node[x].adj.push_back(std::make_pair(y, w));
            node[y].adj.push_back(std::make_pair(x, w));
        }

        for (int j = 0; j < n; j++) {
            int k;
            int min;
            std::cin >> k;
            if (k == 0)
                continue;
            for (int l = 0; l < k; l++) {
                std::cin >> min;
                node[j].occupiedAtMin.push_back(min);
            }
        }

        dijkstra(s);
    }

    delete[] node;

    return 0;
}
