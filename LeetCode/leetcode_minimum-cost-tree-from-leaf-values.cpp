/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> maxval(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++ i) {
            int res = arr[i];
            for(int j = i; j < n; ++ j) {
                res = max(res, arr[j]);
                maxval[i][j] = res;
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return solve(dp, maxval, 0, n - 1);
    }
    
private:
    int solve(vector<vector<int>> &dp, vector<vector<int>> &maxval, int left, int right) {
        if(left >= right) {
            return 0;
        }
        
        if(dp[left][right] != INT_MAX) {
            return dp[left][right];
        }
        
        for(int i = left; i < right; ++ i) {
            int leftval = solve(dp, maxval, left, i);
            int rightval = solve(dp, maxval, i + 1, right);
            int rootval = maxval[left][i]*maxval[i + 1][right];
            dp[left][right] = min(dp[left][right], rootval + leftval + rightval);
        }
        
        return dp[left][right];
    }
};
