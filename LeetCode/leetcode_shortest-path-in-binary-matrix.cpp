/*
*
* Tag: BFS
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
private:
    int dir[8][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid.size() == 0 || grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        if(grid.size() == 1 || grid[0].size() == 1 ){
            return 1;
        }
        
        int ans = -1, m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        q.push({0, 0, 1});
        vis[0][0] = true;
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            
            pair<int,int> cur_pnt = make_pair(cur[0], cur[1]);
            int dis = cur[2];
            for(int i = 0; i < 8; ++ i) {
                int nxt_r = cur_pnt.first + dir[i][0], nxt_c = cur_pnt.second + dir[i][1];
                if(nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m || grid[nxt_r][nxt_c] == 1 || vis[nxt_r][nxt_c]) {
                    continue;
                }
                
                vis[nxt_r][nxt_c] = true;
                if(vis[n - 1][m - 1]){
                    ans = dis + 1;
                    break;
                }
                
                q.push({nxt_r, nxt_c, dis + 1});
            }
            
            if(vis[n - 1][m - 1]){
                break;
            }
        }
        
        return ans;
    }
};
