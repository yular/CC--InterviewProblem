/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        if(nums.size() < 3) {
            return 0;
        }
        
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n, 1));
        for(int i = 1; i < n - 1; ++ i) {
            for(int j = 0; j < i; ++ j) {
                if(nums[i] <= nums[j]) {
                    continue;
                }
                
                dp[0][i] = max(dp[0][i], dp[0][j] + 1);
            }
        }
        
        for(int i = n - 2; i > 0; -- i) {
            for(int j = n - 1; j > i; -- j) {
                if(nums[i] <= nums[j]) {
                    continue;
                }
                
                dp[1][i] = max(dp[1][i], dp[1][j] + 1);
            }
        }
        
        int ans = n;
        for(int i = 1; i < n - 1; ++ i) {
            for(int j = i + 1; j < n; ++ j) {
                if(nums[i] > nums[j]) {
                    ans = min(ans, n - (dp[0][i] + dp[1][j]));
                }
            }
        }
        return ans;
    }
};
