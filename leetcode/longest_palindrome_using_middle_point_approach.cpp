class Solution {
public:
    
    
    void check(int& left_index, int& right_index, int& tmp_left, int& tmp_right, int& max) {
        if(tmp_right - tmp_left > max) {
            max = tmp_right - tmp_left;
            left_index = tmp_left;
            right_index = tmp_right;
        }
    }

    string longestPalindrome(string inp) {
        int maxx = INT_MIN;
        int left_index=-1, right_index=-1;
        for(int i=0; i<inp.size(); i++) {
            int left=i-1;
            int right=i+1;
            // for odd string case
            while(left >= 0 && right < inp.size() && inp[left] == inp[right]) {
                left--;
                right++;
            }
            left++;
            right--;
            check(left_index, right_index, left, right, maxx);

            left = i-1;
            right = i;
            // for even string case
            while(left >= 0 && right < inp.size() && inp[left] == inp[right]) {
                left--;
                right++;
            }
            left++;
            right--;
            check(left_index, right_index, left, right, maxx);
        }

        return inp.substr(left_index, right_index-left_index+1);
    }
};