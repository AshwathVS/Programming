class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> seen_r(9);
        vector<set<char>> seen_c(9);
        set<char> setA, setB, setC;

        for(int i=0; i<9; i++) {
            seen_r[i] = {};
            seen_c[i] = {};
        }

        for(int i=0; i<9; i++) {
            if(i % 3 == 0) {
                setA.clear();
                setB.clear();
                setC.clear();
            }

            for(int j=0; j<9; j++) {
                char c=board[i][j];
                if(c == '.') continue;
                else {
                    if(seen_r[i].find(c) != seen_r[i].end()) return false;
                    if(seen_c[j].find(c) != seen_c[j].end()) return false;

                    seen_r[i].insert(c);
                    seen_c[j].insert(c);

                    int setNum = j / 3;
                    if(setNum == 0) {
                        if(setA.find(c) != setA.end()) return false;
                        setA.insert(c);
                    } else if(setNum == 1) {
                        if(setB.find(c) != setB.end()) return false;
                        setB.insert(c);
                    } else {
                        if(setC.find(c) != setC.end()) return false;
                        setC.insert(c);
                    }
                }
            }
        }


        return true;
    }
};