class Solution {
public:
    bool issign(char& i) {
        return i == '-' || i =='+';
    }

    int myAtoi(string str) {
        int res=0, i=0, size = str.size();
        bool neg = false;
        int xx = INT_MAX/10;
        while(str[i] == ' ') i++;
        
        if(i < size) {
            if(issign(str[i])) {
                neg = (str[i] == '-');
                i++;
            } 

            if(isdigit(str[i])) {
                while(i < size && isdigit(str[i])) {
                    int num = str[i] - '0';

                    if(neg && (res > xx || (res == xx && num >= 8))) return INT_MIN;
                    if(!neg && (res > xx || (res == xx && num >= 7))) return INT_MAX;

                    res = res*10 + num;
                    i++;
                }
            }
        }

        return neg? res * -1 : res;
    }   
};
