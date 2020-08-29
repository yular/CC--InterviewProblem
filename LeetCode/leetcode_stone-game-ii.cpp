/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        if(piles.size() == 0) {
            return 0;
        }
        if(piles.size() == 1) {
            return piles[0];
        }
        
        int n = piles.size();
        vector<int> sum = piles;
        for(int i = n - 2; i >= 0; -- i) {
            sum[i] += sum[i + 1];
        }
        
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        for(int i = 1; i <= n; ++ i) {
            dp[n - 1][i] = piles.back();
        }
        return dfs(piles, sum, dp, 0, n, 1);
    }
private:
    int dfs(vector<int>& piles, vector<int> &sum, vector<vector<int>>& dp, int idx, int n, int m) {
        if(idx >= n) {
            return 0;
        }
        if(dp[idx][min(n, m)] != -1) {
            return dp[idx][min(n, m)];
        }
        
        int minVal = INT_MAX;
        for(int x = 1; x <= 2*m; ++ x) {
            if(idx + x >= piles.size()) {
                minVal = 0;
                break;
            }
            
            minVal = min(minVal, dfs(piles, sum, dp, idx + x, n, max(m, x)));
        }
        dp[idx][min(n, m)] = sum[idx] - minVal;
        return dp[idx][min(n, m)];
    }
};
