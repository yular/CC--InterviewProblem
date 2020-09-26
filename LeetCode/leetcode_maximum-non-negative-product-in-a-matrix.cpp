/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) {
            return -1;
        }
        
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] == 0 || grid[n - 1][m - 1] == 0) {
            return 0;
        }
        
        vector<vector<pair<long long,long long>>> dp(n, vector<pair<long long,long long>>(m, make_pair(1,-1)));
        int ans = -1;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(i == 0 && j == 0){
                    dp[i][j].first = min(dp[i][j].first, (long long)grid[i][j]);
                    dp[i][j].second = max(dp[i][j].second, (long long)grid[i][j]);
                    continue;
                }
                
                if(grid[i][j] == 0) {
                    ans = 0;
                    dp[i][j].first = dp[i][j].second = 0;
                    continue;
                }
                long long minNeg = 1, maxPos = -1, v = 0;
                if(j > 0) {
                    if(dp[i][j - 1].first < 0) {
                        v = dp[i][j - 1].first*grid[i][j];
                        minNeg = min(minNeg, v);
                        maxPos = max(maxPos, v);
                    }
                    if(dp[i][j - 1].second >= 0) {
                        v = dp[i][j - 1].second*grid[i][j];
                        minNeg = min(minNeg, v);
                        maxPos = max(maxPos, v);
                    }
                }
                
                if(i > 0) {
                    if(dp[i - 1][j].first < 0) {
                        v = dp[i - 1][j].first*grid[i][j];
                        minNeg = min(minNeg, v);
                        maxPos = max(maxPos, v);
                    }
                    if(dp[i - 1][j].second >= 0) {
                        v = dp[i - 1][j].second*grid[i][j];
                        minNeg = min(minNeg, v);
                        maxPos = max(maxPos, v);
                    }
                }
                
                if(minNeg > 0 && maxPos < 0) {
                    dp[i][j].first = dp[i][j].second = 0;
                    continue;
                }
                if(minNeg < 0) {
                    dp[i][j].first = min(dp[i][j].first, minNeg);
                }
                if(maxPos >= 0) {
                    dp[i][j].second = max(dp[i][j].second, maxPos);
                }
            }
        }
        return dp[n - 1][m - 1].second < 0? ans == 0? 0 : -1 : dp[n - 1][m - 1].second%MOD;
    }
};
