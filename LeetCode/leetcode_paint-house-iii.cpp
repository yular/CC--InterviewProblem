/*
*
* Tag: DP
* Time: O((mn)^2)
* Space: O(mn)
*/

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        if(m == 0 || n == 0 || target > m) {
            return -1;
        }
        
        vector<vector<int>> cur(n + 1, vector<int>(target + 1, INT_MAX));
        if(houses[0] > 0) {
            cur[houses[0]][1] = 0;
        } else {
            for(int i = 0; i < n; ++ i) {
                cur[i + 1][1] = cost[0][i];
            }
        }
                
        for(int i = 1; i < m; ++ i) {
            vector<vector<int>> nxt(n + 1, vector<int>(target + 1, INT_MAX));
            
            for(int j = 1; j <= n; ++ j) {
                if(houses[i] > 0 && houses[i] != j) {
                    continue;
                }
                
                
                for(int k = 1; k <= min(i + 1, target); ++ k) {
                    
                    for(int l = 1; l <= n; ++ l) {
                        if(j == l) {
                            if(cur[l][k] == INT_MAX) {
                                continue;
                            }
                            
                            
                            int v = houses[i] == j ? 0 : cost[i][j - 1];
                            nxt[j][k] = min(nxt[j][k], cur[l][k] + v);
                            continue;
                        }

                        if(k == 1 || cur[l][k - 1] == INT_MAX) {
                            continue;
                        }

                        int v = houses[i] > 0 ? 0 : cost[i][j - 1];
                        nxt[j][k] = min(nxt[j][k], cur[l][k - 1] + v);
                    }
                }
            }
            
            cur = nxt;
        }
        
        int ans = INT_MAX;
        for(int i = 1; i <= n; ++ i) {
            ans = min(ans, cur[i][target]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
    
};
