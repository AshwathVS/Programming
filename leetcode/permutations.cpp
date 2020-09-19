class Solution {
public:
    vector<vector<int>> res;
    int size;

    void recurse(int start, vector<int>& nums) {
        if(start == size) {
            vector<int> another(size);

            for(int i=0; i<size; i++) another[i] = nums[i];

            res.push_back(another);
            return;
        }

        for(int i=start; i<size; i++) {
            // swap i and start
            int tmp=nums[start];
            nums[start]=nums[i];
            nums[i]=tmp;

            recurse(start+1, nums);

            // swap them back
            tmp=nums[start];
            nums[start]=nums[i];
            nums[i]=tmp;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();
        recurse(0, nums);
        return res;
    }
};