/*
*
* Tag: DP
* Time: O(mn*(2^n))
* Space: O(m*(2^n))
*/

class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int numberWays(vector<vector<int>>& hats) {
        if(hats.size() == 0) {
            return 0;
        }
        
        vector<int> hatDict(50, -1);
        for(vector<int> hat : hats) {
            for(int h : hat) {
                hatDict[h] = 0;
            }
        }
        
        int m = 0;
        for(int i = 0; i < hatDict.size(); ++ i) {
            if(hatDict[i] > -1) {
                hatDict[i] = m ++;
            }
        }
        
        int n = hats.size();
        vector<int> hatPeople(m, 0);
        for(int i = 0; i < hats.size(); ++ i) {
            for(int j = 0; j < hats[i].size(); ++ j) {
                int idx = hatDict[hats[i][j]];
                hatPeople[idx] |= (1<<i);
            }
        }
        
        int bnd = 1<<n;
        vector<vector<long long>> dp(m, vector<long long>(bnd, 0));
        for(int i = 0; i < n; ++ i){
            int mask = 1<<i;
            if((mask&hatPeople[0]) == 0) {
                continue;
            }
            
            dp[0][mask] = 1;
        }
        
        for(int i = 1; i < m; ++ i) {
            for(int j = 0; j < bnd; ++ j) {
                dp[i][j] += dp[i - 1][j];
            }
            
            for(int j = 0; j < n; ++ j){
                int mask = 1<<j;
                if((hatPeople[i]&mask) == 0) {
                    continue;
                }
                ++ dp[i][mask];
                
                for(int k = 0; k < bnd; ++ k) {
                    if((k&mask) > 0) {
                        continue;
                    }
                    
                    int v = k|mask;
                    dp[i][v] = (dp[i][v] + dp[i - 1][k])%MOD;
                }
            }
        }
        return dp[m - 1][bnd - 1];
    }
};
