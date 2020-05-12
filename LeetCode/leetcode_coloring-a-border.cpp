/*
*
* Tag: DFS
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
private:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if(grid.size() == 0) {
            return grid;
        }
        
        int n = grid.size(), m = grid[0].size();
        if(r0 < 0 || r0 >= n || c0 < 0 || c0 >= m) {
            return grid;
        }
        
        vector<vector<int>> ans = grid;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int origin = grid[r0][c0];
        dfs(ans, make_pair(r0, c0), vis, origin, color);
        
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(ans[i][j] == -1) {
                    ans[i][j] = color;
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<int>> &ans, pair<int,int> p, vector<vector<bool>> &vis, int origin, int color) {
        vis[p.first][p.second] = true;
        int n = ans.size(), m = ans[0].size();
        for(int i = 0; i < 4; ++ i) {
            int nxt_r = p.first + dir[i][0], nxt_c = p.second + dir[i][1];
            if(nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m || (ans[nxt_r][nxt_c] != -1 && ans[nxt_r][nxt_c] != origin )) {
                ans[p.first][p.second] = -1;
                break;
            }
        }
        
        for(int i = 0; i < 4; ++ i) {
            int nxt_r = p.first + dir[i][0], nxt_c = p.second + dir[i][1];
            if(nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m || vis[nxt_r][nxt_c] || ans[nxt_r][nxt_c] != origin) {
                continue;
            }
            
            dfs(ans, make_pair(nxt_r, nxt_c), vis, origin, color);
        }
        return ;
    }
};
