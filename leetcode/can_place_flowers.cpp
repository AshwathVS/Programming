class Solution {
public:

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        
        while(i<flowerbed.size() && n > 0) {
            if(flowerbed[i] == 0) {
                bool left = false, right=false;
        
                if(i-1 < 0 || flowerbed[i-1] == 0) left=true;

                if(i+1 >= flowerbed.size() || flowerbed[i+1] == 0) right = true;

                if(left && right) {
                    flowerbed[i] = 1;
                    n--;
                }
            }

            i++;
        }
        
        return n == 0;
    }
};