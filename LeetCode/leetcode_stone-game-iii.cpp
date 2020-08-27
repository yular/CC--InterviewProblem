/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        if(stoneValue.size() == 0) {
            return "Tie";
        }
        if(stoneValue.size() == 1) {
            return stoneValue[0] == 0 ? "Tie" : stoneValue[0] > 0 ? "Alice" : "Bob";
        }
        
        int n = stoneValue.size(), accSum = 0;
        vector<int> dp(n, 0), sum(n, 0);
        for(int i = n - 1; i >= 0; -- i) {
            accSum += stoneValue[i];
            sum[i] = accSum;
            if(i == n - 1) {
                dp[n - 1] = sum[n - 1];
                continue;
            }
            
            int v = dp[i + 1];
            for(int j = 1; i + j < n && j < 4; ++ j) {
                    v = min(v, dp[i + j]);
            }
            dp[i] = sum[i] - v;
            if(i + 3 >= n) {
                dp[i] = max(dp[i], sum[i]);
            }
        }
        
        return dp[0]*2 == sum[0]? "Tie" : dp[0]*2 > sum[0]? "Alice" : "Bob";
    }
};
