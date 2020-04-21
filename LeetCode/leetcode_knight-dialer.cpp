/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
    unordered_map<int, vector<int>> dict;
public:
    int knightDialer(int n) {
        if(n == 0) {
            return 0;
        }
        
        init();
        
        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        for(int i = 0; i < 10; ++ i) {
            dp[1][i] = 1;
        }
        
        for(int i = 2; i <= n; ++ i) {
            for(int j = 0; j < 10; ++ j) {
                for(int k : dict[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k])%MOD;
                }
            }
        }
        
        int sum = 0;
        for(int i = 0; i < 10; ++ i) {
            sum = (sum + dp[n][i])%MOD;
        }
        return sum;
    }
private:
    void init() {
        dict[0] = {4, 6};
        dict[1] = {8, 6};
        dict[2] = {7, 9};
        dict[3] = {4, 8};
        dict[4] = {0, 9, 3};
        dict[5] = {};
        dict[6] = {0, 7, 1};
        dict[7] = {6, 2};
        dict[8] = {1, 3};
        dict[9] = {4, 2};
    }
};
