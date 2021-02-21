/*
*
* Tag: BFS
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
private:
    int dir[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        if(isWater.size() == 0 || isWater[0].size() == 0) {
            return isWater;
        }
        
        int n = isWater.size(), m = isWater[0].size(), front = 0, rear = 0;
        vector<vector<int>> ans = isWater;
        vector<vector<int>> q(n*m);
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(isWater[i][j] == 0) {
                    ans[i][j] = -1;
                } else {
                    ans[i][j] = 0;
                    q[rear ++] = {i, j};
                }
            }
        }
        
        while(front < rear) {
            vector<int> cur = q[front++];
            
            for(int i = 0; i < 4; ++ i) {
                int r = cur[0] + dir[i][0], c = cur[1] + dir[i][1];
                if(r < 0 || r >= n || c < 0 || c >= m || ans[r][c] != -1) {
                    continue;
                }
                
                ans[r][c] = ans[cur[0]][cur[1]] + 1;
                q[rear ++] = {r, c};
            }
        }
        return ans;
    }
};
