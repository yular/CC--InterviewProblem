/*
*
* Tag: DP
* Time: O(k*n^2)
* Space: O(n^2)
*/

class Solution {
    const static int N = 127;
public:
    int getLengthOfOptimalCompression(string s, int k) {
        if(s.size() == 0 || k < 0) {
            return 0;
        }
        
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(0, k, s, dp);
    }
    
private:
    int solve(int left, int k, string &str, vector<vector<int>> &dp) {
        int n = str.size();
        if(left >= n || n - left <= k) {
            return 0;
        }

        if(dp[left][k] != -1) {
            return dp[left][k];
        }        
        dp[left][k] = N;

        vector<int> cnt(26, 0);
        for(int j = left, most = 0; j < n; j++) {
            most = max(most, ++cnt[str[j] - 'a']);
            int restK = k - (j - left + 1 - most);
            if(restK < 0) {
                continue;
            }
            
            dp[left][k] = min(dp[left][k], 1 + getDigitCnt(most) + solve(j + 1, restK, str, dp));
        }
        return dp[left][k];
    }
    
    inline int getDigitCnt(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }
};
