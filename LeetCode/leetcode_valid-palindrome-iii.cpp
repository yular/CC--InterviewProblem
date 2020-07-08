/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        if(s.size() < k) {
            return true;
        }
        
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < s.size(); ++ i){
            for(int j = 0; j < s.size(); ++ j){
                int l = s.size() - 1 - j;
                if(s[i] == s[l]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    continue;
                }
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], max(dp[i + 1][j], dp[i][j + 1]));
            }
        }
        
        return s.size() - dp[n][n] <= k;
    }
};
