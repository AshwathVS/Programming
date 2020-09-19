class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mm;

        for(string i:strs) {
            string cpy = i;
            sort(cpy.begin(), cpy.end());
            if(mm.find(cpy) != mm.end()) {
                mm[cpy].push_back(i);
            } else {
                mm.insert({cpy, {i}});
            }
        }

        vector<vector<string>> res;
        for(pair<string, vector<string>> i : mm) {
            res.push_back(i.second);
        }

        return res;
    }
};