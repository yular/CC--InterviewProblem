/*
*
* Tag: Math
* Time: O(nm)
* Space: O(1)
*/
class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.size() == 0){
            return ans;
        }
        int n = grid.size(), m = grid[0].size();
        int nonEmptyCellCnt = 0;
        vector<int> maxRow(n, 0), maxCol(m, 0);
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(grid[i][j] == 0){
                    continue;
                }
                ++ nonEmptyCellCnt;
                
                for(int k = 0; k < 4; ++ k){
                    int nxtRow = i + dir[k][0], nxtCol = j + dir[k][1];
                    if(nxtRow < 0  || nxtRow >= n || nxtCol < 0 || nxtCol >= m){
                        ans += grid[i][j];
                    } else if(grid[i][j] > grid[nxtRow][nxtCol]) {
                        ans += (grid[i][j] - grid[nxtRow][nxtCol]);
                    }
                }
            }
        }
        
        ans += nonEmptyCellCnt*2;
        
        return ans;
    }
};
