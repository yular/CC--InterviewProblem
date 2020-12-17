/*
*
* Tag: DP
* Time: O(nk)
* Space: O(nk)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int waysToDistribute(int n, int k) {
        if(n < k || n == 0 || k == 0) {
            return 0;
        }
        if(k == 1) {
            return 1;
        }        
        
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        for(int i = 1; i <= n; ++ i) {
            dp[i][1] = 1;
        }
        for(int i = 1; i <= k; ++ i) {
            dp[i][i] = 1;
        }
        
        for(int i = 2; i <= k; ++ i) {
            for(int j = i + 1; j <= n; ++ j) {
                dp[j][i] = (i*dp[j - 1][i] + dp[j - 1][i - 1])%MOD;
            }
        }
        return dp[n][k];
    }
};
