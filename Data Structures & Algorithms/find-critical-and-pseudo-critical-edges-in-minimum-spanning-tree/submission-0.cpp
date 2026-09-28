class DSU {
public:
    explicit DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return false;
        }

        if (rank[a] < rank[b]) {
            swap(a, b);
        }

        parent[b] = a;

        if (rank[a] == rank[b]) {
            ++rank[a];
        }

        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& edges
    ) {
        const int INF = numeric_limits<int>::max();

        // Add the original edge index:
        // [u, v, weight, originalIndex]
        vector<vector<int>> sortedEdges;

        for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
            sortedEdges.push_back({
                edges[i][0],
                edges[i][1],
                edges[i][2],
                i
            });
        }

        sort(
            sortedEdges.begin(),
            sortedEdges.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            }
        );

        auto kruskal = [&](int excluded, int forced) {
            DSU dsu(n);
            int edgeCount = 0;
            int totalWeight = 0;

            // Force this edge into the spanning tree first.
            if (forced != -1) {
                const int u = edges[forced][0];
                const int v = edges[forced][1];
                const int weight = edges[forced][2];

                dsu.unite(u, v);
                ++edgeCount;
                totalWeight += weight;
            }

            for (const auto& edge : sortedEdges) {
                const int u = edge[0];
                const int v = edge[1];
                const int weight = edge[2];
                const int index = edge[3];

                if (index == excluded || index == forced) {
                    continue;
                }

                if (dsu.unite(u, v)) {
                    ++edgeCount;
                    totalWeight += weight;

                    if (edgeCount == n - 1) {
                        break;
                    }
                }
            }

            return edgeCount == n - 1 ? totalWeight : INF;
        };

        const int mstWeight = kruskal(-1, -1);

        vector<int> critical;
        vector<int> pseudoCritical;

        for (int i = 0; i < static_cast<int>(edges.size()); ++i) {
            // If removing the edge increases the MST weight, it is critical.
            const int weightWithout = kruskal(i, -1);

            if (weightWithout > mstWeight) {
                critical.push_back(i);
                continue;
            }

            // Otherwise, force it and check whether an MST is still possible.
            const int weightWith = kruskal(-1, i);

            if (weightWith == mstWeight) {
                pseudoCritical.push_back(i);
            }
        }

        return {critical, pseudoCritical};
    }
};