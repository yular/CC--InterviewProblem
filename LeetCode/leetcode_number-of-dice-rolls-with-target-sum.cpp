/*
*
* Tag: DP
* Time: O(DF*Target)
* Space: O(Target)
*/
class Solution {
private:
    const int MOD = 1e9+7;
public:
    int numRollsToTarget(int d, int f, int target) {
        if(target < 1 || d*f < target) {
            return 0;
        }
        
        vector<vector<int>> dp(2, vector<int>(target + 1, 0));
        for(int i = 1; i <= min(f, target); ++ i) {
            dp[0][i] = 1;
        }
        
        int cur = 1, prev = 0;
        for(int i = 1; i < d; ++ i, cur = (cur + 1)%2) {
            for(int j = min(target, (i+1)*f); j > 0; -- j) {
                dp[cur][j] = 0;
                for(int k = min(j, f); k >= 1; -- k) {
                    if(dp[prev][j - k] <= 0) {
                        continue;
                    }
                    dp[cur][j] = (dp[cur][j] + dp[prev][j - k])%MOD;
                }
            }
            prev = cur;
        }
        return dp[prev][target];
    }
};
