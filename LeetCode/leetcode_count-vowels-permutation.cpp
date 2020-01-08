/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int countVowelPermutation(int n) {
        int ans = 0;
        
        vector<vector<int>> dp(2, vector<int>(5, 0));
        int curIdx = 1, lastIdx = 0;
        for(int i = 0; i < 5; ++ i){
            dp[lastIdx][i] = 1;
        }
        
        for(int len = 1; len < n; curIdx = (curIdx + 1)%2, lastIdx = (lastIdx + 1)%2, ++ len){
            for(int i = 0; i < 5; ++ i){
                dp[curIdx][i] = getSum(i, dp[lastIdx]);
            }
        }
        
        for(int i = 0; i < 5; ++ i){
            ans = (ans + dp[lastIdx][i])%MOD;
        }
        return ans;
    }
private:
    int getSum(int idx, vector<int> &dp) {
        int sum = 0;
        switch(idx){
            case 0:
                // a follows e, i, u
                return ((dp[1] + dp[2])%MOD + dp[4])%MOD;
            case 1:
                // e follows a, i
                return (dp[0] + dp[2])%MOD;
            case 2:
                // i follows e, o
                return (dp[1] + dp[3])%MOD;
            case 3:
                // o follows i
                return dp[2];
            case 4:
                // u follows i, o
                return (dp[2] + dp[3])%MOD;
        }
        return -1;
    }
};
