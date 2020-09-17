bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
    }
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> myvect;
    vector<int> returnPair;
    vector<int> :: iterator it;
    pair<int, int> tmpPair;
    int counter = 0;
    for (it = nums.begin(); it != nums.end(); it++) {
        tmpPair.first = *it;
        tmpPair.second = counter++;
        myvect.push_back(tmpPair);
    }
    sort(myvect.begin(), myvect.end(), compare);
    int start = 0;
    int end = nums.size() - 1;
    while(start < end) {
        int start_num = myvect[start].first;
        int end_num = myvect[end].first;
        if(start_num + end_num == target) {
            returnPair.push_back(myvect[start].second);
            returnPair.push_back(myvect[end].second);
            break;
        }
        else if(start_num + end_num > target) {
            end--;
        }
        else {
            start++;
        }
    }
    //cout << returnPair.first << " " << returnPair.second << endl;
    return returnPair;
    }
};
