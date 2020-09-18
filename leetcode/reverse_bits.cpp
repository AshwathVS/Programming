class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int count=0;

        while(n) {
            short i = n % 2;
            res = (res << 1) + i;
            n/=2;
            count++;
        }

        while(count < 32) {
            count++;
            res = res << 1;
        }
        return res;
    }
};