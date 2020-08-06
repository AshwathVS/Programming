class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& recurse_stack) {
        if(recurse_stack[node]) return false;
        else {
            recurse_stack[node] = true;
            visited[node] = true;
            bool res = true;
            for(int i : graph[node]) {
                if(!res) break;

                if(recurse_stack[i]) return false;

                if(!visited[i]) res = res && dfs(i, graph, visited, recurse_stack);
            }
            recurse_stack[node] = false;
            return res;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>> prereqs) {

        vector<vector<int>> prereq(numCourses);
        for(vector<int> i : prereqs) {
            prereq[i[1]].push_back(i[0]);
        }

        vector<bool> visited(numCourses, false);

        bool canFinish = true;

        for(int i=0; i<prereq.size(); i++) {
            if(!canFinish) break;

            if(!visited[i]) {
                vector<bool> recurse_stack(numCourses, false);
                canFinish = dfs(i, prereq, visited, recurse_stack);
            }
        }

        return canFinish;
    }
};