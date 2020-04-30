/*
*
* Tag: DFS
* Time: O(4^n) n is the total number of cells.
* Space: O(n)
*/

class Solution {
private:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0,  1}};
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int n = grid.size(), m = grid[0].size(), tot = 0;
        pair<int,int> src = make_pair(-1, -1), dst = make_pair(-1, -1);
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(grid[i][j] == 1) {
                    src.first = i, src.second = j;
                } else if(grid[i][j] == 2) {
                    dst.first = i, dst.second = j;
                } else if(grid[i][j] == 0) {
                    ++ tot;
                }
            }
        }
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[src.first][src.second] = true;
        
        int ans = 0;
        dfs(src, dst, grid, vis, 0, tot, ans);
        return ans;
    }
private:
    void dfs(pair<int,int> &cur, pair<int,int> dst, vector<vector<int>>& grid, vector<vector<bool>> &vis, int cnt, int &tot, int &ans) {
        if(cur.first == dst.first && cur.second == dst.second && cnt == tot) {
            ++ ans;
            return ;
        }
        
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < 4; ++ i) {
            int nxt_r = cur.first + dir[i][0], nxt_c = cur.second + dir[i][1];
            if(nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m || grid[nxt_r][nxt_c] == -1 || vis[nxt_r][nxt_c]) {
                continue;
            }
            
            int nxt_cnt = cnt;
            if(grid[nxt_r][nxt_c] == 0) {
                ++ nxt_cnt;
            }
            
            pair<int,int> nxt = make_pair(nxt_r, nxt_c);
            vis[nxt_r][nxt_c] = true;
            dfs(nxt, dst, grid, vis, nxt_cnt, tot, ans);
            vis[nxt_r][nxt_c] = false;
        }
        return ;
    }
};
