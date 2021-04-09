/*
*
* Tag: Graph
* Time: O(n^3)
* Space: O(n^2)
*/

class Solution {
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<int> match(n, -1);
        for(int u = 0; u < m; ++ u) {
            vector<bool> vis(n, false);
            if (dfs(grid, u, vis, match)) {
                ++ res;
            }
        }
        return res;
    }
    
private:
    bool dfs(vector<vector<int>>& grid, int u, vector<bool> &vis, vector<int> &match) {
        int m = grid.size(), n = grid[0].size();
        for(int v = 0; v < n; ++ v) {
            if(grid[u][v] && !vis[v]) {
                vis[v] = true;
                
                if(match[v] < 0 || dfs(grid, match[v], vis, match)) {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

};
