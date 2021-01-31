/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
public:
    bool checkPartitioning(string s) {
        if(s.size() < 3) {
            return false;
        }
        if(s.size() == 3) {
            return true;
        }
        
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false)), formDp(n, vector<bool>(3, false));
        for(int i = n - 1; i >= 0; -- i){
            for(int j = i; j < n; ++ j) {
                if(s[i] != s[j]) {
                    continue;
                }
                
                if(i == j || j == i + 1 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                }
                if(dp[i][j]) {
                    if(j == n - 1) {
                        formDp[i][0] = true;
                    } else if(i == 0 && j < n - 1) {
                        if(formDp[j + 1][1]) {
                            formDp[0][2] = true;
                            return true;
                        }
                    } else if(formDp[j + 1][0]) {
                        formDp[i][1] = true;
                    }
                }
            }
        }
        return false;
    }
};
