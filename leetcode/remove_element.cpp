class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int counter = 0;
        vector<int> :: iterator base = nums.begin();
        vector<int> :: iterator iter = nums.begin();
        
        while (iter != nums.end()) {
            int curr = *iter;
            if (curr != val) {
                *base = curr;
                base++;
                counter++;
            }
            iter++;
        }
        
        
        return counter;
    }
};