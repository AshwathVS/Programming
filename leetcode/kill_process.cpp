class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int, vector<int>> parentMap;
        
        for(int i=0; i<pid.size(); i++) {
            parentMap[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> killed;
        queue<int> q;
        q.push(kill);
        
        while(!q.empty()) {
            int id = q.front();
            q.pop();
            killed.push_back(id);
            for(int childId : parentMap[id]) {
                q.push(childId);
            }
        }
        
        return killed;
    }
};