/*
*
* Tag: DFS
* Time: O(nm)
* Space: O(1)
*/
class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++ i){
            if(grid[i][0] == 0){
                updateGrid(grid, i, 0);
            }
            if(grid[i][grid[0].size() - 1] == 0){
                updateGrid(grid, i, grid[0].size() - 1);
            }
        }
        for(int i = 1; i < grid[0].size() - 1; ++ i){
            if(grid[0][i] == 0){
                updateGrid(grid, 0, i);
            }
            if(grid[grid.size() - 1][i] == 0){
                updateGrid(grid, grid.size() - 1, i);
            }
        }
        
        for(int i = 1; i < grid.size() - 1; ++ i){
            for(int j = 1; j < grid[0].size() - 1; ++ j){
                if(grid[i][j] == 0){
                    ++ ans;
                    updateGrid(grid, i, j);
                }
            }
        }
        return ans;
    }
    
private:
    void updateGrid(vector<vector<int>>&grid, int r, int c){
        grid[r][c] = 1;
        for(int i = 0; i < 4; ++ i){
            int nxtr = r + dir[i][0], nxtc = c + dir[i][1];
            if(nxtr >= 0 && nxtr < grid.size() && nxtc >= 0 && nxtc < grid[0].size() && grid[nxtr][nxtc] == 0) {
                updateGrid(grid, nxtr, nxtc);
            }
        }
    }
};
