/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        if(stones.size() == 0) {
            return stones[0];
        }
        
        int n = stones.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + stones[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 2; len <= n; ++ len) {
            for (int i = 0; i <= n - len; ++ i) {
                int j = i + len - 1;
                dp[i][j] = max(sum[j + 1] - sum[i + 1] - dp[i + 1][j], sum[j] - sum[i] - dp[i][j - 1]);
            }
        }        
        return dp[0][n - 1];
    }
};
