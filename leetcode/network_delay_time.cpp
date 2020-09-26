class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // from, {to, time}
        vector<set<pair<int, int>> > graph(N+1);
        for(auto time : times) {
            graph[time[0]].insert({time[1], time[2]});
        }

        int count=0;

        // time, node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<bool> visited(N, false);

        pq.push({0, K});

        while(!pq.empty()) {
            auto node=pq.top();
            pq.pop();
            if(!visited[node.second]) {
                count++;
                visited[node.second] = true;

                if(count == N) return node.first;

                for(auto neighbor: graph[node.second]) {
                    if(!visited[neighbor.first]) {
                        pq.push({node.first + neighbor.second, neighbor.first});
                    }
                }
            }
        }

        return -1;
    }
};