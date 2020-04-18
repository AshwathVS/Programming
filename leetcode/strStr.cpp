class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        
        int result = -1;
        
        int wstart = 0;
        int wend = needle.length() - 1;
        
        while (wend < haystack.size()) {
            int start = 0;
            if (haystack[wstart] == needle[start]) {
                int i;
                start = wstart;
                for (i = wstart; i <= wend; i++) {
                    if (haystack[i] != needle[i - start]) {
                        break;
                    }
                }
                if (i == wend + 1) {
                    result = start;
                    break;
                }
            }
            
            wstart++;
            wend++;
        }
        
        
        return result;
    }
};