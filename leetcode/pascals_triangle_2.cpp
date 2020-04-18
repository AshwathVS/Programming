class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        int iter = 0;
        while (iter <= rowIndex) {
            vector<int> ele;
            if (iter == 0) {
                ele.push_back(1);
            }
            else {
                ele.push_back(1);
                for (int i = 1; i < prev.size(); i++) {
                    ele.push_back(prev[i] + prev[i - 1]);
                }
                ele.push_back(1);
            }

            prev = ele;
            iter++;
        }
        
        return prev;
    }
};