class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recurse_stack, vector<int>& res) {
        if(recurse_stack[node]) return false;
        else {
            visited[node] = true;
            recurse_stack[node] = true;
            bool intermediateRes = true;
            for(int i : graph[node]) {
                if(!intermediateRes) return false;
                
                if(recurse_stack[i]) return false;
                
                if(!visited[i]) {
                    intermediateRes = intermediateRes && dfs(i, graph, visited, recurse_stack, res);
                }
            }
            recurse_stack[node] = false;
            res.insert(res.begin(), node);
            return intermediateRes;
        }
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        vector<vector<int>> graph(numCourses);
        for(vector<int> i : prereq) {
            graph[i[1]].push_back(i[0]);
        }
        
        vector<bool> visited(numCourses, false);
        vector<int> res;
        for(int i=0; i<numCourses; i++) {
            vector<bool> recurse_stack(numCourses, false);
            
            if(!visited[i]) {
                if(!dfs(i, graph, visited, recurse_stack, res)) return {};
            }
        }
        
        return res;
    }
};