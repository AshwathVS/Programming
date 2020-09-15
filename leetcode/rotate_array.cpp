class Solution {
public:
    void rotate(vector<int>& inp, int k) {
        k %= inp.size();
        int count=0;
        for(int i=0; count < inp.size(); i++) {
            int curr = i;
            int prev = inp[curr];
            do {
                int next=(curr + k) % inp.size();
                int temp = inp[next];
                inp[next] = prev;
                prev = temp;
                curr = next;
                count++;
            } while(curr != i);
        }
        
    }
};