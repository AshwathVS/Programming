class Solution {
public:
    int gcd(int a, int b) {
        if(a == 0) return b;
        else return gcd(b%a, a);
    }

    int gcd(vector<int> m) {
        int res=m[0];

        for(int i=1; i<m.size(); i++) {
            res = gcd(res, m[i]);
            if(res == 1) return 1;
        }
        cout << res << endl;
        return res;
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> m;
        for(int i=0; i<deck.size(); i++) {
            m[deck[i]]++;
        }

        vector<int> counts(m.size());
        for(pair<int, int> i : m) {
            counts.push_back(i.second);
        }

        // for each count value, we have to find the greatest common divisor
        return gcd(counts) >= 2;
    }
};