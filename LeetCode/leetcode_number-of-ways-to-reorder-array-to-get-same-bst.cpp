/*
*
* Tag: DFS + DP
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int numOfWays(vector<int>& nums) {
        if(nums.size() < 3) {
            return 0;
        }
        
        int n = nums.size();
        vector<vector<long long>> dp(n + 1);
        for(int i = 0; i < n + 1; ++i){
            dp[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
            }
        }
        
        long long ans = dfs(nums, dp);
        return ans%MOD - 1;
    }
private:
    long long dfs(vector<int>& nums, vector<vector<long long>> &dp) {
        int n = nums.size();
        if(n < 3) {
            return 1;
        }
        
        vector<int> leftNums, rightNums;
        for(int i = 1; i < n; ++ i) {
            if(nums[i] < nums[0]) {
                leftNums.push_back(nums[i]);
            } else {
                rightNums.push_back(nums[i]);
            }
        }
        
        long long leftRes = 1, rightRes = 1;
        int leftSize = leftNums.size(), rightSize = rightNums.size();
        if(leftSize > 0) {
            leftRes = dfs(leftNums, dp);
        }
        if(rightSize > 0) {
            rightRes = dfs(rightNums, dp);
        }
        
        long long res = (((dp[n - 1][leftSize] * leftRes) % MOD) * rightRes) % MOD;
        return res;
    }
};
