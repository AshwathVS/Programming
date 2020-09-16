class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        map<int, int> rainedLakes;
        vector<int> res(rains.size(), 0);
        set<int> dryDays;

        for(int i=0; i<rains.size(); i++) {
            int val = rains[i];

            if(val == 0) {
                dryDays.insert(i);
                res[i] = 1;
            }
            else {
                if(rainedLakes.find(val) != rainedLakes.end()) {
                    auto it = dryDays.upper_bound(rainedLakes[val]);
                    if(it == dryDays.end()) return {};
                    else {
                        res[*it] = val;
                        res[i] = -1;
                        rainedLakes[val] = i;
                        dryDays.erase(it);
                    }
                } else {
                    rainedLakes.insert({val, i});
                    res[i] = -1;
                }
            }

        }

        return res;
    }
};