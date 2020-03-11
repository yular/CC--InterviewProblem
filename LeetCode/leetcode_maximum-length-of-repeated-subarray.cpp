/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.size() == 0 && B.size() == 0){
            return 0;
        }
        
        int n = A.size(), m = B.size(), ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(A[i] != B[j]) {
                    continue;
                }
                
                dp[i + 1][j + 1] = dp[i][j] + 1;
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans;
    }
};
