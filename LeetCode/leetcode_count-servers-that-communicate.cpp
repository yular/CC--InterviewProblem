/*
*
* Tag: Brute Force, Array
* Time: O(nm)
* Space: O(n)
*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        
        int n = grid.size(), m = grid[0].size();
        vector<int> colCnt(m, 0), lastColOfComputer(n, 0), rowCnt(n, 0);
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if(grid[i][j] == 0) {
                    continue;
                }
                
                ++rowCnt[i], ++ colCnt[j], lastColOfComputer[i] = j;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++ i){
            if(rowCnt[i] == 1 && colCnt[lastColOfComputer[i]] == 1) {
                continue;
            }
            ans += rowCnt[i];
        }
        return ans;
    }

};
