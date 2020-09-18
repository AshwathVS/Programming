class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 0 || numRows == 1) return s;

        int row=0;
        string res="";
        int size = s.size();

        while(row < numRows) {
            if(row == 0 || row == numRows-1) {
                int i=row;
                while(i < size) {
                    res += s[i];
                    i += (2*numRows - 2);
                }
            } else {
                int i=row;
                bool low = true;
                while(i < size) {
                    res += s[i];
                    if(low) {
                        i += (2* (numRows - 1 - row));
                    } else {
                        i += (2 * row);
                    }

                    low = !low;
                }
            }
            row++;
        }


        return res;
    }
};