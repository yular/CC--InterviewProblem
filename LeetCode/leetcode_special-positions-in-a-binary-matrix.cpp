/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(n + m)
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        if(mat.size() == 0 || mat[0].size() == 0) {
            return 0;
        }
        
        int n = mat.size(), m = mat[0].size();
        vector<int> rowCnt(n, 0), colCnt(m, 0);
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                rowCnt[i] += mat[i][j];
                colCnt[j] += mat[i][j];
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(mat[i][j] == 1 && rowCnt[i] == 1 && colCnt[j] == 1) {
                    ++ ans;
                }
            }
        }
        return ans;
    }
};
