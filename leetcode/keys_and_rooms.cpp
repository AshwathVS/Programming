class Solution {
public:
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> toVisit;
        vector<bool> visited(rooms.size(), false);
        
        toVisit.push(0);
        
        while(!toVisit.empty()) {
            int room=toVisit.top();
            toVisit.pop();
            
            visited[room] = true;
            
            for(int canVisit: rooms[room]) {
                if(!visited[canVisit]) toVisit.push(canVisit);
            }
        }
        
        
        for(bool i : visited) {
            if(!i) return false;
        }
        
        return true;
    }
};