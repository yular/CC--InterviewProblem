/*
*
* Tag: BFS
* Time: O(n^2)
* Space: O(n^2)
*/

class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};    
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, n*m));
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(grid[i][j] == 1) {
                    q.push(make_pair(i, j));
                    dis[i][j] = 0;
                }
            }
        }
        
        if(q.empty() || q.size() == n*m) {
            return -1;
        }
        
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            
            for(int i = 0; i < 4; ++ i) {
                int r = cur.first + dir[i][0], c = cur.second + dir[i][1];
                if(r < 0 || r >= n || c < 0 || c >= m || dis[cur.first][cur.second] + 1 >= dis[r][c]) {
                    continue;
                }
                
                dis[r][c] = dis[cur.first][cur.second] + 1;
                q.push(make_pair(r, c));
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                ans = max(ans, dis[i][j]);
            }
        }
        return ans;
    }
};
