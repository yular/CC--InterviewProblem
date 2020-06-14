/*
*
* Tag: DP
* Time: O(k*n^2)
* Space: O(n^2)
*/

class Solution {
public:
    int minDistance(vector<int>& houses, int K) {
        int n = houses.size();
        if(n == K) {
            return 0;
        }
        
        sort(houses.begin(), houses.end());
        
        vector<vector<int>> dis(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++ i) {
            for(int j = i + 1; j < n; ++ j) {
                for(int k = i; k <= j; ++ k) {
                    dis[i][j] += abs(houses[k] - houses[(j + i)/2]);
                }
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(K + 1, INT_MAX));
        for(int i = 0; i < n; ++ i) {
            dp[i][1] = dis[0][i];
        }
        
        for(int k = 2; k <= K; ++ k){
            for(int i = k - 1; i < n; ++ i){
                for(int j = 0; j < i; ++ j){
                    if(dp[j][k - 1] == INT_MAX) {
                        continue;
                    }
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + dis[j + 1][i]);
                }
            }
        }
        return dp[n - 1][K];
    }
};
