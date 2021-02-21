/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        if(word1.size() == 0 || word2.size() == 0) {
            return 0;
        }
                
        int n = word1.size(), m = word2.size(), ans = 0;
        
        string s = word1 + word2;
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N, 1));
        for(int i = N - 2; i >= 0; -- i){
            for(int j = i + 1; j < N; ++ j){
                if(s[i] == s[j]){
                    dp[i][j] = j == i + 1 ? 2 : max(dp[i][j], dp[i + 1][j - 1] + 2);
                    if(i < n && j >= n) {
                        ans = max(dp[i][j], ans);
                    }
                }
                dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j - 1]));
            }
        }
        return ans;
    }
};
