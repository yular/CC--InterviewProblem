/*
*
* Tag: DP
* Time: O(lgn)
* Space: O(1)
*/
class Solution {
public:
    int minimumOneBitOperations(int n, int res=0) {
        if(n == 0) {
            return 0;
        }
        
        vector<long long> dp(32, 0);
        long long mask = 2;
        for(int i = 0; i < 32; ++ i, mask <<= 1) {
            dp[i] = (mask - 1);
        }
        
        long long ans = 0, idx = 30;
        while(n > 0) {
            while(idx >= 0 && (1L<<idx) > n) {
                -- idx;
            }
            if(idx > 0) {
                ans += dp[idx - 1] + 1;
            } else {
                ans += dp[0];
            }
            
            if(idx > 0) {
                n = (n^(1L<<idx)^((1L<<(idx - 1))));
            } else {
                n = 0;
            }
        }
        return ans;
    }
};
