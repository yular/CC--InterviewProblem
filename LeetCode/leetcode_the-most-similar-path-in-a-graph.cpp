/*
*
* Tag: DP
* Time: O(m*n^2) m is the length of target path
* Space: O(n^2)
*/

class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        if(targetPath.size() == 0) {
            return {};
        }
        
        vector<vector<bool>> g(n, vector<bool>(n, false));
        for(vector<int> road : roads){
            g[road[0]][road[1]] = g[road[1]][road[0]] = true;
        }
        
        int m = targetPath.size(), idx = 0;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX)), path(m, vector<int>(n, -1));
        for(int i = 0; i < n; ++ i) {
            dp[0][i] = 1;
            if(names[i] == targetPath[0]) {
                dp[0][i] = 0;
                idx = i;
            }
        }
        
        int minVal = INT_MAX;
        for(int i = 1; i < m; ++ i) {
            for(int j = 0; j < n; ++ j) {
                for(int k = 0; k < n; ++ k) {
                    if(!g[k][j]) {
                        continue;
                    }
                    
                    int v = dp[i - 1][k];
                    if(targetPath[i] != names[j]) {
                        ++ v;
                    }
                    
                    if(dp[i][j] > v) {
                        dp[i][j] = v;
                        path[i][j] = k;
                    }
                }
                
                if(i == m - 1) {
                    if(dp[i][j] < minVal) {
                        minVal = dp[i][j];
                        idx = j;
                    }
                }
            }
        }
        
        vector<int> ans(m, 0);
        for(int i = m - 1; i >= 0; -- i) {
            ans[i] = idx;
            idx = path[i][idx];
        }
        return ans;
    }
};
