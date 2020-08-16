/*
*
* Tag: DP (DFS)
* Time: O(lgn)
* Space: O(lgn)
*/

class Solution {
public:
    int minDays(int n) {
        if(n <= 1) {
            return n;
        }
        
        unordered_map<int,int> dp;
        dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 2;
        dfs(dp, n);
        
        return dp[n];
    }
private:
    void dfs(unordered_map<int,int> &dp, int n) {
        if(dp.count(n) > 0) {
            return ;
        }
        
        dp[n] = n;
        if(n%2 == 0) {
            dfs(dp, n/2);
            dp[n] = min(dp[n], dp[n/2] + 1);
        } else {
            dfs(dp, n/2);
            dp[n] = min(dp[n], dp[n/2] + 2);
        }
        
        if(n%3 == 0) {
            dfs(dp, n/3);
            dp[n] = min(dp[n], dp[n/3] + 1);
        } else if(n%3 == 1){
            dfs(dp, (n - 1)/3);
            dp[n] = min(dp[n], dp[(n - 1)/3] + 2);
        } else {
            dfs(dp, (n - 2)/3);
            dp[n] = min(dp[n], dp[(n - 2)/3] + 3);
        }
        
        return ;
    }
};
