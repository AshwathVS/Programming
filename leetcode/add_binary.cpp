class Solution {
public:
    string addBinary(string a, string b)
{
    string ret = "";

    int i = a.length() - 1, j = b.length() - 1, rem = 0;

    while (i >= 0 && j >= 0)
    {
        int a_val = a[i] - 48;
        int b_val = b[j] - 48;

        // cout << "a_val: " << a_val << endl;
        // cout << "b_val: " << b_val << endl;

        int sum = rem + a_val + b_val;
        //cout << "T_SUM: " << sum << endl;
        int val = sum % 2;
        rem = sum / 2;
        //cout << "REM: " << rem << endl;

        ret = (char)(val + 48) + ret;

        i--;
        j--;
    }

    if (i >= 0)
    {
        while (i >= 0) {
            int sum = rem + (a[i] - 48);
            //cout << "A_SUM: " << sum << endl;
            int val = sum % 2;
            rem = sum / 2;

            //cout << "REM: " << rem << endl;
            ret = (char)(val + 48) + ret;
            //cout << "RET: " << ret << endl;
            i--;
        }
    }

    if (j >= 0)
    {
        while (j >= 0) {
            int sum = rem + (b[j] - 48);
            //cout << "B_SUM: " << sum << endl;
            int val = sum % 2;
            rem = sum / 2;

            //cout << "REM: " << rem << endl;
            ret = (char)(val + 48) + ret;
            //cout << "RET: " << ret << endl;
            j--;
        }
    }

    if (rem > 0)
    {
        //cout << "REM: " << rem << endl;
        ret = (char)(rem + 48) + ret;
        //cout << "RET: " << ret << endl;
    }

    return ret;
}

};