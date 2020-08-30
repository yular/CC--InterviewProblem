/*
*
* Tag: Greedy
* Time: O((nm)^2)
* Space: O(nm)
*/

class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int minDays(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int n = grid.size(), m = grid[0].size();
        if(n == 1 && m == 1) {
            return grid[0][0];
        }
        
        int cnt = getIslandCnt(grid);
        if(cnt > 1 || cnt == 0) {
            return 0;
        }
        
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(grid[i][j] == 0) {
                    continue;
                }
                
                grid[i][j] = 0;
                cnt = getIslandCnt(grid);
                if(cnt > 1) {
                    return 1;
                }
                grid[i][j] = 1;
            }
        }
        return 2;
    }
private:
    int getIslandCnt(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(grid[i][j] == 0 || vis[i][j]) {
                    continue;
                }
                
                ++ cnt;
                dfs(i, j, grid, vis);
            }
        }
        return cnt;
    }
    
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>> &vis) {
        vis[r][c] = true;
        
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < 4; ++ i){
            int nxt_r = r + dir[i][0], nxt_c = c + dir[i][1];
            if(nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m || grid[nxt_r][nxt_c] == 0 || vis[nxt_r][nxt_c]) {
                continue;
            }
            
            dfs(nxt_r, nxt_c, grid, vis);
        }
        return ;
    }
};
