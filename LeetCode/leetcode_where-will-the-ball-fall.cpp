/*
*
* Tag: DFS
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return {};
        }
        
        int n = grid.size(), m = grid[0].size();
        vector<int> ans(m, 0);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < m; ++ i) {
            dfs(0, i, grid, vis, ans, i);
        }
        return ans;
    }
private:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &vis, vector<int> &ans, int idx) {
        int n = grid.size(), m = grid[0].size();
        if(c < 0 || c >= m) {
            ans[idx] = -1;
            return ;
        }
        if(r >= n) {
            ans[idx] = c;
            return ;
        }
        
        if(vis[r][c] != 0) {
            ans[idx] = vis[r][c];
            return ;
        }
        
        if(grid[r][c] == 1) {
            if(c + 1 < m && grid[r][c + 1] == -1) {
                ans[idx] = -1;
            } else {
                dfs(r + 1, c + 1, grid, vis, ans, idx);
            }
        } else {
            if(c - 1 >= 0 && grid[r][c - 1] == 1) {
                ans[idx] = -1;
            } else {
                dfs(r + 1, c - 1, grid, vis, ans, idx);
            }
        }
        
        vis[r][c] = ans[idx];
        return ;
    }
};
