/*
*
* Tag: DP (Greedy)
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        if(cuboids.size() == 0) {
            return 0;
        }
        
        for(vector<int> &c : cuboids) {
            sort(c.begin(), c.end());
        }
        
        sort(cuboids.begin(), cuboids.end());
        
        int n = cuboids.size();
        vector<int> dp(n);
        for(int i = 0; i < n; ++ i) {
            dp[i] = cuboids[i][2];
        }
        
        int ans = dp[0];
        for(int i = 1; i < n; ++ i) {
            for(int j = 0; j < i; ++ j) {
                if(cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
