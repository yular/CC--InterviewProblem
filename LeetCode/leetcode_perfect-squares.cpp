/*
*
* Tag: DP
* Time: O()
* Space: O()
*/
class Solution {
public:
    int numSquares(int n) {
        if(n <= 1)
            return 1;
        vector<int> rcd(n), dp(n + 1);
        int cnt = 0, bnd = sqrt(n*1.0);
        for(int i = 1; i <= bnd; ++ i){
            rcd[cnt ++] = i*i;
        }
        for(int i = 1; i <= n; ++ i){
            dp[i] = n + 1;
        }
        for(int i = 0; i < cnt; ++ i){
            dp[rcd[i]] = 1;
        }
        for(int i = 1; i < n; ++ i){
            if(dp[i] == -1)
                continue;
            for(int j = 0; j < cnt; ++ j){
                int nd = i + rcd[j];
                if(nd > n)
                    break;
                dp[nd] = min(dp[nd], dp[i] + 1);
            }
        }
        return dp[n];
    }
};
