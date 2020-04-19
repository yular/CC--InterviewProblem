/*
*
* Tag:DP
* Time: O(n)
* Space: O(n)
*/

class Solution {
private:
    const int MOD = 1e9+7;
public:
    int numberOfArrays(string s, int k) {
        if(k < 1 || s.size() == 0 || s[0] == '0') {
            return 0;
        }
        
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; ++ i) {
            long long v = 0, fact = 1;
            for(int j = i, cnt = 0; j >= 0 && cnt <= 9; -- j, ++ cnt, fact *= 10) {
                v = fact*(s[j] - '0') + v;
                if(v > k) {
                    break;
                }
                if(v < 1 || s[j] == '0') {
                    continue;
                }
                
                if(j == 0) {
                    dp[i] = (dp[i] + 1)%MOD;
                } else {
                    dp[i] = (dp[i] + dp[j - 1])%MOD;
                }
            }
            
            if(dp[i] == 0) {
                break;
            }
        }
        return dp[n - 1];
    }
};
