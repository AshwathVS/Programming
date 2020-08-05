class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<set<int>> g(graph.size());
        for(int i=0; i<g.size(); i++) {
            g[i] = {};
        }
        
        for(int i=0; i<graph.size(); i++) {
            for(int edge : graph[i]) {
                g[i].insert(edge);
            }
        }
        
        vector<int> color(graph.size(), -1);
        
        while(true) {
            int i;
            for(i=0; i<graph.size(); i++) {
                if(color[i] == -1) break;
            }
            
            bool col = false;
            if(i == graph.size()) break;
            else {
                queue<int> source;
                for(int neighbor : g[i]) {
                    if(color[neighbor] != -1) {
                        col = !color[neighbor];
                        break;
                    }
                }
                
                color[i] = col;
                source.push(i);
                
                while(!source.empty()) {
                    int node = source.front();
                    source.pop();
                    int neighborColor = !color[node];
                    
                    for(int neighbor : g[node]) {
                        if(color[neighbor] == -1) {
                            color[neighbor] = neighborColor;
                            source.push(neighbor);
                        }
                        
                        if(color[neighbor] != -1 && color[neighbor] != neighborColor) return false;
                    }
                }
            }
        }
        
        return true;

    }
};