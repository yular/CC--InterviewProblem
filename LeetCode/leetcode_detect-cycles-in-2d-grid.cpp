/*
*
* Tag: DFS
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    bool containsCycle(vector<vector<char>>& grid) {
        if(grid.size() < 2 || grid[0].size() == 0) {
            return false;
        }
        
        bool hasCircle = false;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j) {
                if(vis[i][j]) {
                    continue;
                }
                
                vector<int> lastPos = {-1, -1}, curPos = {i, j};
                dfs(lastPos, curPos, hasCircle, vis, grid);
                
                if(hasCircle) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    void dfs(vector<int> &lastPos, vector<int> &curPos, bool &hasCircle, vector<vector<bool>> &vis, vector<vector<char>>& grid) {
        vis[curPos[0]][curPos[1]] = true;
        
        char c = grid[curPos[0]][curPos[1]];
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < 4; ++ i) {
            int nxt_i = curPos[0] + dir[i][0], nxt_j = curPos[1] + dir[i][1];
            if(nxt_i < 0 || nxt_i >= n || nxt_j < 0 || nxt_j >= m || (nxt_i == lastPos[0] && nxt_j == lastPos[1]) || grid[nxt_i][nxt_j] != c ){
                continue;
            }
            
            if(vis[nxt_i][nxt_j]) {
                hasCircle = true;
                break;
            }
            
            vector<int> nxtPos = {nxt_i, nxt_j};
            dfs(curPos, nxtPos, hasCircle, vis, grid);
        }
        
        return ;
    }
};
