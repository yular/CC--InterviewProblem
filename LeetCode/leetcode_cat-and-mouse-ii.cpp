/*
*
* Tag: DFS
* Time: O(s*max(catjump, mousejump)*(nm)^2)
* Space: O(s(nm)^2)
* Credit: https://leetcode.com/problems/cat-and-mouse-ii/discuss/1020573/Game-ends-about-70-moves-C%2B%2B
*/

class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1 ,0}, {0, -1}, {0, 1}};
    int dp[1010][8][8][8][8];
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        if(grid.size() == 0) {
            return true;
        }
        memset(dp, -1, sizeof(dp));
        
        int mx = 0, my = 0, cx = 0, cy = 0, n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(grid[i][j] == 'C') {
                    cx = i, cy = j;
                }
                if(grid[i][j] == 'M') {
                    mx = i, my = j;
                }
            }
        }
        return dfs(1, cx, cy, mx, my, grid, catJump, mouseJump, 0);
    }
private:
    bool dfs(int step, int cx, int cy, int mx, int my, vector<string>& grid, int catJump, int mouseJump, int state) {
        if(dp[step][mx][my][cx][cy] != -1) {
            return dp[step][mx][my][cx][cy];
        }
        
        int n = grid.size(), m = grid[0].size();
        bool isWin = false;
        if(state == 0) {
            // mouse turn
            if(mx == cx && my == cy) {
                return false;
            }
            if(step >= 70) {
                return false;
            }
            if(grid[cx][cy] == 'F') {
                return false;
            }
            if(grid[mx][my] == 'F') {
                return true;
            }
            
            for(int i = 0; i < 4; ++ i) {
                for(int j = 0; j <= mouseJump; ++ j) {
                    int Mx = mx + j*dir[i][0], My = my + j*dir[i][1];
                    if(Mx < 0 || Mx >= n || My < 0 || My >= m || grid[Mx][My] == '#') {
                        break;
                    }
                    if(!dfs(step + 1, cx, cy, Mx, My, grid, catJump, mouseJump, (state + 1)%2)) {
                        isWin = true;
                        break;
                    }
                }
                if(isWin) {
                    break;
                }
            }
        } else {
            // cat turn
            if(mx == cx && my == cy) {
                return true;
            }
            if(step >= 70) {
                return true;
            }
            if(grid[cx][cy] == 'F') {
                return true;
            }
            if(grid[mx][my] == 'F') {
                return false;
            }
            
            for(int i = 0; i < 4; ++ i) {
                for(int j = 0; j <= catJump; ++ j) {
                    int Cx = cx + j*dir[i][0], Cy = cy + j*dir[i][1];
                    if(Cx < 0 || Cx >= n || Cy < 0 || Cy >= m || grid[Cx][Cy] == '#') {
                        break;
                    }
                    if(!dfs(step + 1, Cx, Cy, mx, my, grid, catJump, mouseJump, (state + 1)%2)) {
                        isWin = true;
                        break;
                    }
                }
                if(isWin) {
                    break;
                }
            }
        }
        dp[step][mx][my][cx][cy] = isWin;
        
        return isWin;
    }
};
