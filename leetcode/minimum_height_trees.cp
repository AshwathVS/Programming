class Solution {
public:
   vector<int> findMinHeightTrees(int size, vector<vector<int>> edges) {
        if(edges.size() == 0) return {0};
        vector<set<int>> g(size);
        for(vector<int> v: edges) {
            g[v[0]].insert(v[1]);
            g[v[1]].insert(v[0]);
        }

        queue<int> q;
        for(int i=0; i<g.size(); i++) {
            if(g[i].size() == 1) {
                q.push(i);
            }
        }

        int n = size;

        while(n > 2) {
            n -= q.size();
            int _s = q.size();
            while(_s--) {
                int neighbor = g[q.front()].begin().operator*();
                g[neighbor].erase(q.front());
                q.pop();
                if(g[neighbor].size() == 1) q.push(neighbor);
            }
        }
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }

};