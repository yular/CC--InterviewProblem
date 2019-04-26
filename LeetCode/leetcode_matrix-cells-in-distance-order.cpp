/*
*
* Tag: BFS
* Time: O(rc)
* Space: O(rc)
*/
class Solution {
private:
    int dir[4][2]={{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        queue<vector<int>> q;
        vector<vector<int>> cells(R*C);
        vector<vector<bool>> vis(R, vector<bool>(C, false));
        int idx = 0;
        q.push({r0, c0});
        vis[r0][c0] = true;
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            cells[idx ++] = cur;
            
            int curR = cur[0], curC = cur[1];
            for(int i = 0; i < 4; ++ i){
               int nxtR = curR + dir[i][0], nxtC = curC + dir[i][1];
                if(nxtR < 0 || nxtR >= R || nxtC < 0 || nxtC >= C || vis[nxtR][nxtC]) {
                    continue;
                }
                
                vis[nxtR][nxtC] = true;
                q.push({nxtR,nxtC});
            }
        }
        return cells;
    }
};
