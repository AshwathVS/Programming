class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);

        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            auto index = q.front();
            q.pop();

            visited[index] = true;

            if (arr[index] == 0) return true;

            int right = index + arr[index];
            int left = index - arr[index];
            cout << "index " << index << ", left " << left << ", right " << right << endl;
            if (right < arr.size() && !visited[right]) q.push(right);

            if (left >= 0 && !visited[left]) q.push(left);

        }

        return false;
    }
};