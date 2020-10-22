/*
*
* Tag: DP
* Time: O(sum*n)
* Space: O(sum)
*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size() == 0) {
            return 0;
        }
        int sum = 0;
        for(int stone : stones) {
            sum += stone;
        }
        
        int n = stones.size(), m = sum/2;
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for(int i = 0; i < n; ++ i) {
            for(int j = m; j >= stones[i]; -- j) {
                if(dp[j - stones[i]]) {
                    dp[j] = true;
                }
            }
        }
        
        for(int i = m; i > 0; -- i) {
            if(dp[i]) {
                return sum - 2*i;
            }
        }
        return -1;
    }
};
