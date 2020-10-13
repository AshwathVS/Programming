class Solution {
public:
    vector<vector<int>> graph;
    int dest;
    
    void explorePath(vector<vector<int>>& allPaths, vector<int>& pathTaken, int node) {
        if(node == dest) allPaths.push_back(pathTaken);
        else {
            for(int neighbor : graph[node]) {
                pathTaken.push_back(neighbor);
                explorePath(allPaths, pathTaken, neighbor);
                pathTaken.pop_back();
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        graph = g;
        dest = graph.size() - 1;
        vector<vector<int>> res;
        vector<int> pathTaken;
        pathTaken.push_back(0);
        explorePath(res, pathTaken, 0);
        
        return res;
    }
};