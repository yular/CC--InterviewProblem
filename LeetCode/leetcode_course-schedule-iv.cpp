/*
*
* Tag: Graph (Floyd)
* Time: O(n^3)
* Space: O(n^2)
*/

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        if(queries.size() == 0) {
            return {};
        }
        
        vector<bool> ans(queries.size(), false);
        if(prerequisites.size() == 0) {
            return ans;
        }
        
        vector<vector<bool>> g(n, vector<bool>(n, false));
        for(vector<int> pre : prerequisites) {
            g[pre[0]][pre[1]] = true;
        }
        
        for(int i = 0; i < n; ++ i) {
            g[i][i] = true;
        }
        
        for(int k = 0; k < n; ++ k) {
            for(int i = 0; i < n; ++ i) {
                for(int j = 0; j < n; ++ j) {
                    if(g[i][j]) {
                        continue;
                    }
                    g[i][j] = (g[i][k]&g[k][j]);
                }
            }
        }
        
        for(int i = 0; i < queries.size(); ++ i) {
            vector<int> q = queries[i];
            ans[i] = g[q[0]][q[1]];
        }
        return ans;
    }
};
