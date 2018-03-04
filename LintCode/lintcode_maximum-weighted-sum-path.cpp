/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm) (In optimal solution, it is O(m))
*/
class Solution {
public:
    int maxWeight(vector<vector<int>> &nums) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<int>> dp(nums);
        
        for(int i = 0; i < n; ++ i){
            for(int j = m - 1; j >= 0; -- j){
                int maxSum = dp[i][j];
                if(isInGrid(i, j + 1, n, m))
                    maxSum = max(maxSum, nums[i][j] + dp[i][j + 1]);
                if(isInGrid(i - 1, j, n, m))
                    maxSum = max(maxSum, nums[i][j] + dp[i - 1][j]);
                dp[i][j] = maxSum;
            }
        }
        
        return dp[n - 1][0];
    }
    
private:
    bool isInGrid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >=0 && j < m;
    }
};
