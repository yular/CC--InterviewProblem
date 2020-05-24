/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n == 0 || m == 0) {
            return 0;
        }
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        dp[0][0] = nums1[0]*nums2[0];
        for(int i = 1; i < n; ++ i) {
            int v = nums1[i]*nums2[0];
            dp[i][0] = max(dp[i - 1][0], v);
        }
        for(int i = 1; i < m; ++ i) {
            int v = nums1[0]*nums2[i];
            dp[0][i] = max(dp[0][i - 1], v);
        }
        
        for(int i = 1; i < n; ++ i) {
            for(int j = 1; j < m; ++ j) {
                int v = nums1[i]*nums2[j];
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + v);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], v);
            }
        }
        return dp[n - 1][m - 1];
    }
};
