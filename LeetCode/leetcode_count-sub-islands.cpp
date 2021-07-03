/*
*
* Tag: DFS
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        if(grid1.size() == 0 || grid2.size() == 0){
            return 0;
        }
        if(grid1.size() != grid2.size() || grid1[0].size() != grid2[0].size()) {
            return 0;
        }
        int n = grid2.size(), m = grid2[0].size(), cnt = 0;
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(grid2[i][j] != 1) {
                    continue;
                }
                
                bool isSubIsland = true;
                dfs(grid1, grid2, i, j, isSubIsland);
                
                if(isSubIsland) {
                    ++ cnt;
                }
            }
        }
        return cnt;
    }
private:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, bool &isSubIsland) {
        if(grid1[r][c] != grid2[r][c]) {
            isSubIsland = false;
        }
        grid2[r][c] = 0;
        
        int n = grid2.size(), m = grid2[0].size();
        for(int i = 0; i < 4; ++ i) {
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid2[nr][nc] != 1) {
                continue;
            }
            dfs(grid1, grid2, nr, nc, isSubIsland);
        }
        return ;
    }
};
