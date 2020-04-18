class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        int iter = 0;
        while (iter < numRows) {
            vector<int> ele;
            if (iter == 0) {
                ele.push_back(1);
                res.push_back(ele);
            } else {
                vector<int> prev = res[iter - 1];
                ele.push_back(1);
                for (int i = 1; i < prev.size(); i++) {
                    ele.push_back(prev[i] + prev[i - 1]);
                }
                ele.push_back(1);
                
                res.push_back(ele);
            }
            
            iter++;
        }
        return res;
    }
};