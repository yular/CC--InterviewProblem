/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int ans = INT_MAX;
        
        int numOfRows = A.size(), numOfCols = A[0].size();
        vector<vector<int>> dp(2, vector<int>(numOfCols));
        for(int i = 0; i < numOfCols; ++ i){
            dp[0][i] = A[0][i];
            dp[1][i] = INT_MAX;
        }
        
        for(int i = 1; i < numOfRows; ++ i){
            for(int j = 0; j < numOfCols; ++ j){
                if(j > 0) {
                    dp[1][j] = min(dp[1][j], dp[0][j - 1] + A[i][j]);
                }
                
                dp[1][j] = min(dp[1][j], dp[0][j] + A[i][j]);
                
                if(j < numOfCols - 1){
                    dp[1][j] = min(dp[1][j], dp[0][j + 1] + A[i][j]);
                }
            }
            
            for(int j = 0; j < numOfCols; ++ j){
                dp[0][j] = dp[1][j];
                dp[1][j] = INT_MAX;
            }
        }
        
        for(int i = 0; i< numOfCols; ++ i){
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};
