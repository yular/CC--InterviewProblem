/*
*
* Tag: Implementation
* Time: O(nmlgm)
* Space: O(nm)
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        if(mat.size() == 0){
            return mat;
        }
        
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++ i){
            vector<int> tmp(min(m, n - i));
            for(int j = 0; i + j < n && j < m; ++ j){
                tmp[j] = mat[i + j][j];
            }
            
            sort(tmp.begin(), tmp.end());
            for(int j = 0; i + j < n && j < m; ++ j){
                 ans[i + j][j] = tmp[j];
            }
        }
        
        for(int i = 1; i < m; ++ i){
            vector<int> tmp(min(n, m - i));
            for(int j = 0; i + j < m && j < n; ++ j){
                tmp[j] = mat[j][i + j];
            }
            
            sort(tmp.begin(), tmp.end());
            for(int j = 0; i + j < m && j < n; ++ j){
                 ans[j][i + j] = tmp[j];
            }
        }
        return ans;
    }
};
