/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        if(A.size() == 0 || B.size() == 0) {
            return 0;
        }
        
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for(int i = 0; i < A.size(); ++ i){
            for(int j = 0; j < B.size(); ++ j){
                if(A[i] == B[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    continue;
                }
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], max(dp[i + 1][j], dp[i][j + 1]));
            }
        }
        return dp[A.size()][B.size()];
    }
};
