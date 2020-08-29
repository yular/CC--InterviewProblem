/*
*
* Tag: DP
* Time: O(n*target)
* Space: O(n*target)
*/

class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        if(prob.size() == 0) {
            return 0;
        }
        
        int n = prob.size();
        vector<vector<double>> dp(n, vector<double>(target + 2, 0));
        dp[0][0] = 1 - prob[0], dp[0][1] = prob[0];
        for(int i = 1; i < n; ++ i) {
            dp[i][0] += dp[i - 1][0]*(1 - prob[i]);
            for(int j = 1; j <= i + 1 && j <= target; ++ j) {
                dp[i][j] += (dp[i - 1][j]*(1 - prob[i]) + dp[i - 1][j - 1]*prob[i]);
            }
        }
        return dp[n - 1][target];
    }
};
