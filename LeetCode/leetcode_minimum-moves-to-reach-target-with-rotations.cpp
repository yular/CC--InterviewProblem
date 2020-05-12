/*
*
* Tag: BFS
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
private:
    const int dir[2][2] = {{1, 0}, {0, 1}};
public:
    int minimumMoves(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() < 2) {
            return 0;
        }
        
        int n = grid.size(), m = grid[0].size();
        int MAX_VAL = n*m + 10;
        vector<vector<vector<int>>> dis(n, vector<vector<int>>(m, vector<int>(2, MAX_VAL)));
        dis[0][0][0] = dis[0][1][0] = 0;
        queue<vector<int>> q;
        q.push({0, 1, 0});
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            
            int state = cur[2];
            if(state == 0 && cur[0] == n - 1 && cur[1] == m - 1) {
                break;
            }
            for(int i = 0; i < 2; ++ i) {
                int nxt_r = cur[0] + dir[i][0], nxt_c = cur[1] + dir[i][1];
                vector<int> nxt(3, 0);
                if(state == 0) {
                    if(nxt_r >= n || nxt_c >= m || grid[nxt_r][nxt_c] == 1 || (i == 0 && grid[nxt_r][nxt_c - 1] == 1) || dis[nxt_r][nxt_c][state] <= dis[cur[0]][cur[1]][state] + 1) {
                        continue;
                    }
                } else {
                    if(nxt_r >= n || nxt_c >= m || grid[nxt_r][nxt_c] == 1 || (i == 1 && grid[nxt_r - 1][nxt_c] == 1) || dis[nxt_r][nxt_c][state] <= dis[cur[0]][cur[1]][state] + 1) {
                        continue;
                    }
                }
                
                dis[nxt_r][nxt_c][state] = dis[cur[0]][cur[1]][state] + 1;
                nxt[0] = nxt_r, nxt[1] = nxt_c, nxt[2] = state;
                q.push(nxt);
            }
            
            if(state == 0) {
                if(cur[1] - 1 < 0 || cur[0] + 1 >= n || grid[cur[0] + 1][cur[1] - 1] == 1 || grid[cur[0] + 1][cur[1]] == 1 ||  dis[cur[0] + 1][cur[1] - 1][1] <= dis[cur[0]][cur[1]][state] + 1) {
                    continue;
                }
                
                dis[cur[0] + 1][cur[1] - 1][1] = dis[cur[0]][cur[1]][state] + 1;
                q.push({cur[0] + 1, cur[1] - 1, 1});
            } else {
                if(cur[0] - 1 < 0  || cur[1] + 1 >= m || grid[cur[0] - 1][cur[1] + 1] == 1 || grid[cur[0]][cur[1] + 1] == 1 || dis[cur[0] - 1][cur[1] + 1][0] <= dis[cur[0]][cur[1]][state] + 1) {
                    continue;
                }
                
                dis[cur[0] - 1][cur[1] + 1][0] = dis[cur[0]][cur[1]][state] + 1;
                q.push({cur[0] - 1, cur[1] + 1, 0});
            }
        }
        
        return dis[n - 1][m - 1][0] == MAX_VAL? -1 : dis[n - 1][m - 1][0];
    }
};
