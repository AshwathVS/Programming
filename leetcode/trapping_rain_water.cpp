class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if(size <= 2) return 0;
        int res = 0;

        
        int currMax = 0;
        int currWater = 0;
        for(int i=1; i<size; i++) {
            if(height[i] >= height[currMax]) {
                res += currWater;
                currWater = 0;
                currMax = i;
            } else {
                currWater += (height[currMax] - height[i]);
            }
        }
        
        
        if(currMax < size-1) {
            int rightMax = size-1;
            for(int i=size-2; i>currMax; i--) {
                if(height[i] >= height[rightMax]) {
                    rightMax = i;
                } else {
                    res += (height[rightMax] - height[i]);
                }
            }
        } else {
            res += currWater;
        }
        
        return res;
    }
};