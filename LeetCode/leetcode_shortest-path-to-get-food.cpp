/*
*
* Tag: BFS
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int getFood(vector<vector<char>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int sx = -1, sy = -1;
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(grid[i][j] == '*') {
                    sx = i, sy = j;
                    break;
                }
            }
            if(sx != -1) {
                break;
            }
        }
        if(sx == -1) {
            return -1;
        }
        
        queue<vector<int>> q;
        q.push({sx, sy, 0});
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            vis[cur[0]][cur[1]] = true;
            if(grid[cur[0]][cur[1]] == '#') {
                return cur[2];
            }
            
            for(int i = 0; i < 4; ++ i) {
                int tx = cur[0] + dir[i][0], ty = cur[1] + dir[i][1];
                if(tx < 0 || tx >= n || ty < 0 || ty >= m || grid[tx][ty] == 'X' || vis[tx][ty]) {
                    continue;
                }
                
                q.push({tx, ty, cur[2] + 1});
                vis[tx][ty] = true;
            }
        }
        return -1;
    }
};
