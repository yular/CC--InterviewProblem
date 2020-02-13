/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1 == text2) {
            return text1.size();
        }
        if(text1.size() == 0 || text2.size() == 0) {
            return 0;
        }
        
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for(int i = 0; i < text1.size(); ++ i){
            for(int j = 0; j < text2.size(); ++ j){
                if(text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    continue;
                }
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], max(dp[i + 1][j], dp[i][j + 1]));
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
