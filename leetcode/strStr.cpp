class Solution {
public:
    int strStr(string haystack, string needle) {
        int nsize = needle.size();

        if(nsize == 0) return 0;
        else if(haystack.size() < nsize) return -1;

        int result = -1;
        int start = 0, end = nsize-1;

        while(start+nsize-1 <= haystack.size()) {
            int tmpstart = start, i=0, nextstart = start+nsize;
            bool found = false;

            while(tmpstart <= end) {

                if(tmpstart > start && haystack[tmpstart] == needle[0]) {
                    found = true;
                    nextstart = min(nextstart, tmpstart);
                }

                if(haystack[tmpstart] != needle[i]) break;

                i++;
                tmpstart++;
            }

            if(tmpstart == end + 1) {
                result = start;
                break;
            } else {
                if(found) start = nextstart;
                else start++;
                end = start + nsize-1;
            }
        }

        return result;
    }
};
