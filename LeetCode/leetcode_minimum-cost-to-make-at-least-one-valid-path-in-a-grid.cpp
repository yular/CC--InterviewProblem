/*
*
* Tag: BFS
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
private:
    const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int minCost(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        
        queue<pair<int,int>> q;
        q.push(make_pair(0, 0));
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            
            for(int i = 0; i < 4; ++ i) {
                int nxt_r = cur.first + dir[i][0], nxt_c = cur.second + dir[i][1];
                if(nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m) {
                    continue;
                }
                
                int v = grid[cur.first][cur.second] - 1 == i? 0 : 1;
                if(dis[nxt_r][nxt_c] > dis[cur.first][cur.second] + v) {
                    dis[nxt_r][nxt_c] = dis[cur.first][cur.second] + v;
                    q.push(make_pair(nxt_r, nxt_c));
                }
            }
        }
        
        return dis[n - 1][m - 1];
    }
};
