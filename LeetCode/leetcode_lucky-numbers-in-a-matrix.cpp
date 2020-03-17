/*
*
* Tag: Hash
* Time: O(nm)
* Space: O(n) + O(m)
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        if(matrix.size() == 0) {
            return {};
        }
        
        int n = matrix.size(), m = matrix[0].size();
        vector<int> minRow(n, INT_MAX), maxCol(m, INT_MIN);
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j) {
                minRow[i] = min(minRow[i], matrix[i][j]);
                maxCol[j] = max(maxCol[j], matrix[i][j]);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j) {
                if(matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};
