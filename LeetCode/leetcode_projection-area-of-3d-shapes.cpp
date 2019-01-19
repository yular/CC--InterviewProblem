/*
*
* Tag: Math
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.size() == 0 || grid[0].size() == 0){
            return ans;
        }
        
        int n = grid.size(), numOfValidCells = 0;
        vector<int> maxRow(n, 0), maxCol(n, 0);
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < n; ++ j){
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxCol[j] = max(maxCol[j], grid[i][j]);
                numOfValidCells += grid[i][j] == 0 ? 0 : 1;
            }
        }
        
        for(int i = 0; i < n; ++ i){
            ans += maxRow[i] + maxCol[i];
        }
        ans += numOfValidCells;
        return ans;
    }
};
