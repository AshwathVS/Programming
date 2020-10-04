class CombinationIterator {
private:
    queue<string> combinations;
    int _LEN;
    string str;
    int strSize;

    void calcCombinations(string rollingStr, int start, int len) {
        if(len == 0) combinations.push(rollingStr);
        else if(start >= str.size()) return;
        else {
            for(int i=start; i+len-1 < strSize; i++) {
                calcCombinations(rollingStr + str[i], i+1, len-1);
            }
        }
    }

public:

    CombinationIterator(string characters, int combinationLength) {
        _LEN = combinationLength;
        str = characters;
        strSize = str.size();

        calcCombinations("", 0, _LEN);
    }

    string next() {
        string res = combinations.front();
        combinations.pop();
        return res;
    }

    bool hasNext() {
        return !combinations.empty();
    }
};
