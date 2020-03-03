/*
*
* Tag: Math
* Time: O(nm)
* Space: O(1)
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k == 0){
            return grid;
        }
        
        int n = grid.size(), m = grid[0].size();
        int size = n*m;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                int nxt = (i*m + j + k)%size;
                ans[nxt/m][nxt%m] = grid[i][j];
            }
        }
        return ans;
    }
};
