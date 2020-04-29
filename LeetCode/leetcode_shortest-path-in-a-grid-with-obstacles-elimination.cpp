/*
*
* Tag: BFS
* Time: O(nmk)
* Space: O(nmk)
*/

class Solution {
private:
    const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        if(grid.size() == 0 || (grid.size() == 1 && grid[0].size() == 1) ) {
            return 0;
        }
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dis(n, vector<vector<int>>(m, vector<int>(k + 1, INT_MAX)));
        for(int i = 0; i <= k; ++ i){
            dis[0][0][i] = 0;
        }
        
        int ans = -1;
        queue<vector<int>> q;
        q.push({0,0,0});
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            
            for(int i = 0; i < 4; ++ i) {
                int nxt_r = cur[0] + dir[i][0], nxt_c = cur[1] + dir[i][1], curk = cur[2];
                if(nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m || (grid[nxt_r][nxt_c] == 0 && dis[nxt_r][nxt_c][curk] <= dis[cur[0]][cur[1]][curk] + 1) || (grid[nxt_r][nxt_c] == 1 && (curk + 1 > k || dis[nxt_r][nxt_c][curk + 1] <= dis[cur[0]][cur[1]][curk] + 1 ) ) ) {
                    continue;
                }
                
                int nxt_k = curk;
                if(grid[nxt_r][nxt_c] == 1) {
                    ++ nxt_k;
                }
                
                dis[nxt_r][nxt_c][nxt_k] = dis[cur[0]][cur[1]][curk] + 1;
                if(nxt_r == n - 1 && nxt_c == m - 1) {
                    ans = dis[cur[0]][cur[1]][curk] + 1;
                    break;
                }
                q.push({nxt_r, nxt_c, nxt_k});
            }
            if(ans != -1) {
                break;
            }
        }
        return ans;
    }
};
