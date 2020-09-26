class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // cost, {hop, node}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<pair<int, int>>> graph(n);

        for (vector<int> v : flights) {
            graph[v[0]].push_back({v[1], v[2]});
        }

        pq.push({0, {0, src}});

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int currNode = node.second.second;

            if (node.second.first > K + 1) continue;
            else {
                if (currNode == dst) {
                    return node.first;
                } else {
                    // append neighbors
                    for (auto neighbor : graph[currNode]) {
                        pq.push({node.first + neighbor.second,
                                 {
                                         node.second.first + 1, neighbor.first
                                 }
                                }
                        );
                    }
                }
            }
        }

        return -1;
    }
};