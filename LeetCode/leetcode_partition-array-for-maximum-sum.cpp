/*
*
* Tag: DP
* Time: O(nk)
* Space: O(n^2)
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        if(A.size() == 0 || K == 0) {
            return 0;
        }
        
        int n = A.size();
        vector<vector<int>> maxSub(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++ i) {
            int maxVal = A[i];
            for(int j = i; j < min(i + K, n); ++ j) {
                maxVal = max(maxVal, A[j]);
                maxSub[i][j] = maxVal;
            }
        }
        
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++ i) {
            for(int j = i; j >= max(0, i - K + 1); -- j){
                if(j == 0) {
                    dp[i] = maxSub[0][i]*(i + 1);
                    continue;
                }
                dp[i] = max(dp[i], dp[j - 1] + maxSub[j][i]*(i - j + 1));
            }
        }
        return dp[n - 1];
    }
};
