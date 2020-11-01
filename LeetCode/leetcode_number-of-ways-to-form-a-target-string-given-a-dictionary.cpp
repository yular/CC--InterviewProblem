/*
*
* Tag: DP
* Time: O(n*m)
* Space: O(m)
*/

class Solution {
private:
    int MOD = 1e9+7;
public:
    int numWays(vector<string>& words, string target) {
        if(words.size() == 0 || words[0].size() < target.size()) {
            return 0;
        }
        
        int n = words[0].size(), m = target.size();
        long long ans = 0;
        vector<long long> dp(m + 1, 0), sum(m + 1, 0);
        for(int i = 0; i < n; ++ i) {
            vector<int> charCnt(26, 0);
            for(int j = 0; j < words.size(); ++ j) {
                int idx = words[j][i] - 'a';
                ++ charCnt[idx];
            }
            
            for(int j = 1; j <= i + 1 && j <= m; ++ j) {
                int idx = target[j - 1] - 'a';
                if(charCnt[idx] == 0) {
                    continue;
                }
                if(j == 1) {
                    dp[j] = charCnt[idx];
                    continue;
                }
                
                dp[j] = (dp[j] + sum[j - 1]*charCnt[idx])%MOD;
            }
            ans = (ans + dp[m])%MOD;
            
            for(int j = 1; j <= i + 1 && j <= m; ++ j) {
                sum[j] = (sum[j] + dp[j])%MOD;
                dp[j] = 0;
            }
        }        
        return ans;
    }
};
