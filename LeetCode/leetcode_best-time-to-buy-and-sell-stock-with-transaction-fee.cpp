/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() < 2) {
            return 0;
        }
        
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] = -prices[0]-fee;
        for(int i = 1; i < n; ++ i){
            dp[1][0] = max(dp[0][0], dp[0][1] - prices[i] - fee);
            dp[1][1] = max(dp[0][1], dp[0][0] + prices[i]);
            dp[0][0] = dp[1][0], dp[0][1] = dp[1][1];
        }
        return max(dp[1][0], dp[1][1]);
    }
};
