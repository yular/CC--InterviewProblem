/*
*
* Tag: DP, DFS
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        if(stoneValue.size() < 2) {
            return 0;
        }
                
        int n = stoneValue.size(), s = 0;
        vector<int> sum(n, 0);
        for(int i = 0; i < n; ++ i) {
            s += stoneValue[i];
            sum[i] = s;
        }
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(0, n - 1, dp, stoneValue, sum);
    }
private:
    int dfs(int start, int end, vector<vector<int>> &dp, vector<int>& stoneValue, vector<int> &sumVec) {
        if(dp[start][end] >= 0) {
            return dp[start][end];
        }
        if(start >= end) {
            dp[start][end] = 0;
            return dp[start][end];
        }
        
        int sum = sumVec[end];
        if(start > 0) {
            sum -= sumVec[start - 1];
        }
        
        int res = &dp[start][end], leftSum = 0;
        for(int i = start; i < end; ++ i) {
            leftSum += stoneValue[i];
            
            int doubleSum = leftSum*2, totSum = 0;
            if(doubleSum < sum) {
                totSum = leftSum;
                totSum += dfs(start, i, dp, stoneValue, sumVec);
            } else if(doubleSum > sum) {
                totSum = sum - leftSum;
                totSum += dfs(i + 1, end, dp, stoneValue, sumVec);
            } else {
                totSum = leftSum;
                totSum += max(dfs(start, i, dp, stoneValue, sumVec), dfs(i + 1, end, dp, stoneValue, sumVec) );
            }
            
            res = max(res, totSum);
        }
        dp[start][end] = res;
        return dp[start][end];
    }
};
