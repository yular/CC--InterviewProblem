/*
*
* Tag: DP
* Time: O(nk)
* Space: O(nk)
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        if(events.size() == 0) {
            return 0;
        }
        
        sort(events.begin(), events.end());
        
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        
        int ans = 0;
        dfs(events, dp, 0, k, n, ans);
        return ans;
    }
    
private:
    int dfs(vector<vector<int>>& events, vector<vector<int>> &dp, int cur, int k, int n, int &ans) {
        if(cur >= n || k <= 0) {
            return 0;
        }
        
        if(dp[cur][k] != -1) {
            return dp[cur][k];
        }
        
        int res = max(dfs(events, dp, cur + 1, k, n, ans), events[cur][2]);
        for(int i = cur + 1; i < n; i ++) {
            if(events[i][0] <= events[cur][1]) {
                continue;
            }
            res = max(res, events[cur][2] + dfs(events, dp, i, k - 1, n, ans) );
            break;
        }
        dp[cur][k] = res;
        ans = max(ans, res);
        return res;
    }
};
