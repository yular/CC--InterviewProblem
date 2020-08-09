/*
*
* Tag: DP
* Time: O(n^3)
* Space: O(n^2)
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        if(n == 0) {
            return 0;
        }
        
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size() + 1;
        vector<int> dis(m, 0);
        dis[0] = cuts[0], dis[m - 1] = n - cuts.back();
        for(int i = 1, j = 1; i < cuts.size(); ++ i, ++ j) {
            dis[j] = cuts[i] - cuts[i - 1];
        }
        
        vector<vector<int>> sum(m, vector<int>(m, 0));
        vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
        for(int i = 0; i < m; ++ i){
            int res = 0;
            for(int j = i; j < m; ++ j) {
                res += dis[j];
                sum[i][j] = res;
            }
            dp[i][i] = 0;
        }
        
        for(int k = 1; k < m; ++ k) {
            for(int l = 0; l + k < m; ++ l) {
                int r = l + k;
                for(int i = l; i < r; ++ i){
                    dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + sum[l][r]);
                }
            }
        }
        return dp[0][m - 1];
    }
};
