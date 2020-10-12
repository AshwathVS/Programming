class Solution {
public:
    vector<int> findAllCommas(string& str) {
        vector<int> res;
        for(int i=0; i<str.size(); i++) {
            if(str[i] == ',') res.push_back(i);
        }

        return res;
    }

    struct Transaction {
        string name;
        int time;
        int amount;
        string city;

        string toString() {
            return name + "," + to_string(time) + "," + to_string(amount) + "," + city;
        }
    };

    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<Transaction> vv;
        for(string trans : transactions) {
            vector<int> commas = findAllCommas(trans);
            string name = trans.substr(0, commas[0]);
            int time = stoi(trans.substr(commas[0]+1, commas[1]-commas[0]));
            int amount = stoi(trans.substr(commas[1]+1, commas[2]-commas[1]));
            string city = trans.substr(commas[2] + 1, trans.size() - commas[2]);
            vv.push_back({name, time, amount, city});
        }

        sort(vv.begin(), vv.end(), [](Transaction& a, Transaction& b){
            return a.time < b.time;
        });

        map<string, vector<Transaction>> checkup;
        set<string> invalid;

        for(auto t : vv) {
            if(t.amount > 1000) invalid.insert(t.toString());

            if(checkup.find(t.name) != checkup.end()) {
                vector<Transaction> transactions = checkup[t.name];
                int low = 0, high = transactions.size()-1;

                for(int i=transactions.size()-1; i >= 0 && abs(transactions[i].time - t.time) <= 60; i--) {
                    if(transactions[i].city != t.city) {
                        invalid.insert(transactions[i].toString());
                        invalid.insert(t.toString());
                    }
                }
            }

            checkup[t.name].push_back(t);
        }


        vector<string> res;
        for(string str : invalid) res.push_back(str);
        return res;
    }
};