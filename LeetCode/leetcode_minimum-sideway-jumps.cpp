/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        if(obstacles.size() == 0) {
            return 0;
        }
        
        int n = obstacles.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        dp[0][0] = dp[0][2] = 1, dp[0][1] = 0;
        for(int i = 1; i < n; ++ i) {
            for(int j = 0; j < 3; ++ j) {
                if(obstacles[i] == j + 1) {
                    dp[i][j] = -1;
                    continue;
                }
                
                for(int k = 0; k < 3; ++ k) {
                    if(obstacles[i] == k + 1) {
                        continue;
                    }
                    
                    if(k == j) {
                        if(dp[i - 1][j] != -1) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                        }
                    } else {
                        if(dp[i - 1][k] != -1) {
                            dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
                        }
                    }
                }
            }
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};
