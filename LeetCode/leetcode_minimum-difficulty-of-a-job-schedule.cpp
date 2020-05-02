/*
*
* Tag: DP
* Time: O(nd)
* Space: O(nd)
*/

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d){
            return -1;
        }
        
        vector<vector<int>> maxVal(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++ i){
            int curMax = jobDifficulty[i];
            for(int j = i; j < n; ++ j){
                curMax = max(curMax, jobDifficulty[j]);
                maxVal[i][j] = curMax;
            }
        }
        
        vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d, INT_MAX));
        for(int i = 0; i < d; ++ i){
            for(int j = i; j < n; ++ j){
                if(i == 0){
                    dp[j][i] = maxVal[0][j];
                    continue;
                }
                for(int k = 1; k <= j; ++ k){
                    if(dp[k - 1][i - 1] == INT_MAX){
                        continue;
                    }
                    dp[j][i] = min(dp[j][i], dp[k - 1][i - 1] + maxVal[k][j]);
                }
            }
        }
        
        return dp[n - 1][d - 1];
    }
};
