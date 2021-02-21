/*
*
* Tag: DP
* Time: O(m^2)
* Space: O(m^2)
*/

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        if(nums.size() == 0 || nums.size() < multipliers.size()) {
            return 0;
        }
        
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(1010, vector<int>(1010, INT_MIN));
        return dfs(0, 0, n - 1, nums, multipliers, dp);
    }
private:
    int dfs(int idx, int l, int r, vector<int>& nums, vector<int>& multipliers, vector<vector<int>> &dp) {
        if(idx >= multipliers.size() || l > r) {
            return 0;
        }
        
        int bnd = nums.size() - r - 1;
        if(dp[l][bnd] != INT_MIN) {
            return dp[l][bnd];
        }
        int res = nums[l]*multipliers[idx] + dfs(idx + 1, l + 1, r, nums, multipliers, dp);
        res = max(res, nums[r]*multipliers[idx] + dfs(idx + 1, l, r - 1, nums, multipliers, dp));
        dp[l][bnd] = res;
        return dp[l][bnd];
    }
};
