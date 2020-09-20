/*
*
* Tag: DP
* Time: O(nm*(2^m))
* Space: O(n*(2^m))
*/

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int sz1 = cost.size();
        if(sz1 == 0) {
            return 0;
        }
        int sz2 = cost[0].size();
        if(sz2 == 0) {
            return 0;
        }
        
        int n = (1<<sz2);
        vector<vector<int>> dp(sz1 + 1, vector<int>(n, (1<<29)));
        dp[sz1][n - 1] = 0;
        for(int i = sz1 - 1; i >= 0; -- i){
            for(int j = n - 1; j >= 0; -- j){
                for(int k = 0; k < sz2; ++ k){
                    int v = (1<<k);
                    dp[i][j] = min(dp[i][j], cost[i][k] + dp[i + 1][j|v]);
                    if((j&v) == 0) {
                        dp[i][j] = min(dp[i][j], cost[i][k] + dp[i][j|v]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
