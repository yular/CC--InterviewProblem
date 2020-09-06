/*
*
* Tag: DP
* Time: O(fuel*n^2)
* Space: O()
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        if(locations.size() == 0  || fuel == 0) {
            return 0;
        }
        
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
        dp[start][0] = 1;
        for(int i = 1; i <= fuel; ++ i){
            for(int t = 0; t < n; ++ t){
                for(int s = 0; s < n; ++ s) {
                    int v = abs(locations[s] - locations[t]);
                    if(s == t || v > i || dp[s][i - v] == -1) {
                        continue;
                    }
                    
                    if(dp[t][i] == -1){
                        dp[t][i] = 0;
                    }
                    dp[t][i] = (dp[t][i] + dp[s][i - v])%MOD;
                }
            }
        }
        
        int ans = 0;
        if(start == finish) {
            ans = 1;
        }
        for(int i = 1; i <= fuel; ++ i) {
            if(dp[finish][i] == -1) {
                continue;
            }
            ans = (ans + dp[finish][i])%MOD;
        }
        return ans;
    }
};
