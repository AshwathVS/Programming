class Solution {
public:
    int lengthOfLongestSubstring(string inpString) {
        set<char> distinctSet;
        set<char> :: iterator it;
        // string inpString = s;
        // cout << "Enter string: " << endl;
        // cin >> inpString;
        int maxLength = 0;
        int startPointer = 0;
        for(int i = 0; i < inpString.length(); i++) {
            it = distinctSet.find(inpString[i]);
            if(it != distinctSet.end()) {
                while(inpString[startPointer] != inpString[i]) {
                    distinctSet.erase(inpString[startPointer]);
                    startPointer++;
                }
                distinctSet.erase(inpString[startPointer]);
                startPointer++;
                distinctSet.insert(inpString[i]);
            }
            else {
                distinctSet.insert(inpString[i]);
            }

            if(distinctSet.size() > maxLength) {
                    maxLength = distinctSet.size();
            }

        }
            return maxLength;
        }
};