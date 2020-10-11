class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mm;
        vector<string> tmp;
        vector<string> res;

        for(string str : words) mm[str]++;

        for(auto it : mm) tmp.push_back(it.first);

        sort(tmp.begin(), tmp.end(), [&mm](string a, string b) {
            return mm[a] == mm[b] ? a < b : mm[a] > mm[b];
        });

        for(int i=0; i<k; i++) res.push_back(tmp[i]);

        return res;
    }

};