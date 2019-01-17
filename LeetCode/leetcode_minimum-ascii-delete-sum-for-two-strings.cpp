/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, INT_MAX));
        
        dp[0][0] = 0;
        for(int i = 0; i < s1.size(); ++ i){
            dp[i + 1][0] = dp[i][0] + (int)s1[i];
        }
        for(int i = 0; i < s2.size(); ++ i){
            dp[0][i + 1] = dp[0][i] + (int)s2[i];
        }
        
        for(int i = 0; i < s1.size(); ++ i){
            for(int j = 0; j < s2.size(); ++ j){
                if(s1[i] == s2[j]){
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (int)s1[i] + (int)s2[j]);
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i + 1][j] + (int)s2[j]);
                    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j + 1] + (int)s1[i]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
