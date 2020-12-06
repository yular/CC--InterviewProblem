/*
*
* Tag: Bit Manipulation
* Time: O(nlgn)
* Space: O(1)
*/
class Solution {
private:
    int bitCnt[19] = {0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
    int MOD = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        if(n == 1) {
            return n;
        }
        
        long long ans = 0;
        for(int i = 1, idx = 1; i <= n; ++ i) {
            int b = idx - 1;
            if(i == bitCnt[idx]) {
                ++ b;
                ++ idx;
            }
            ans <<= b;
            ans |= i;
            ans %= MOD;
        }
        return ans;
    }
};
