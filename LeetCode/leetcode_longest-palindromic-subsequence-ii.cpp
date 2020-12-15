/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() < 2) {
            return 0;
        }
        
        int n = s.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(26, 0)));
        for(int i = 0; i + 1 < n; ++ i) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1][s[i] - 'a'] = 2;
            }
        }
        
        for(int len = 2; len < n; ++ len) {
            for(int i = 0; i + len < n; ++ i){
                int j = i + len;
                int u = s[i] - 'a', v = s[j] - 'a';
                
                if(u == v) {
                    for(int k = 0; k < 26; ++ k) {
                        if(u != k) {
                            dp[i][j][u] = max(dp[i][j][u], dp[i + 1][j - 1][k] + 2);
                        }
                    }
                    
                    for(int k = 0; k < 26; ++ k) {
                        if(u != k) {
                            dp[i][j][k] = dp[i + 1][j - 1][k];
                        }
                    }
                } else {
                    dp[i][j][u] = dp[i][j - 1][u];
                    dp[i][j][v] = dp[i + 1][j][v];
                    for(int k = 0; k < 26; ++ k) {
                        if(u != k && v != k) {
                            dp[i][j][k] = dp[i + 1][j - 1][k];
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < 26; ++ i) {
            ans = max(ans, dp[0][n - 1][i]);
        }
        return ans;
    }
};
