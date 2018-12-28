/*
* Tag: Math
* Time: O(nm)
* Space: O(n+m)
*/
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ans = 0;
        if(grid.size() == 0){
            return ans;
        }
        vector<int> maxRow(grid.size(), 0), maxCol(grid[0].size(), 0);
        for(int i = 0; i < grid.size(); ++ i){
            for(int j = 0; j < grid[0].size(); ++ j){
                maxRow[i] = max(maxRow[i], grid[i][j]);
                maxCol[j] = max(maxCol[j], grid[i][j]);
            }
        }
        
        for(int i = 0; i < grid.size(); ++ i){
            for(int j = 0; j < grid[0].size(); ++ j){
                if(grid[i][j] < min(maxRow[i], maxCol[j])){
                    ans += (min(maxRow[i], maxCol[j]) - grid[i][j]);
                }
            }
        }
        return ans;
    }
};
