/*
*
* Tag: DP
* Time: O(kn^2)
* Space: O(nk)
*/

class Solution {
public:
    int palindromePartition(string s, int k) {
        if(s.size() == 0 || k == 0) {
            return 0;
        }
        
        int n = s.size();
        vector<vector<int>> palindScore(n, vector<int>(n, -1));
        vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
        for(int i = 0; i < n; ++ i) {
            for(int j = i; j < n; ++ j) {
                palindScore[i][j] = calPalindScore(i, j, s);
                if(i == 0) {
                    dp[j][0] = palindScore[0][j];
                }
            }
        }
        
        for(int l = 1; l < k; ++ l){
            for(int i = 1; i < n; ++ i) {
                for(int j = i; j >= 1; -- j) {
                    if(dp[j - 1][l - 1] == INT_MAX) {
                        continue;
                    }
                    dp[i][l] = min(dp[i][l], dp[j - 1][l - 1] + palindScore[j][i]);
                }
            }
        }
        return dp[n - 1][k - 1];
    }
    
private:
    int calPalindScore(int start, int end, string &s) {
        int res = 0;
        for(int i = start, j = end; i <= j; ++ i, -- j){
            if(s[i] != s[j]) {
                ++ res;
            }
        }
        return res;
    }
};
