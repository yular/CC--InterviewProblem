/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        if(mat.size() == 0 || mat[0].size() == 0) {
            return 0;
        }
        
        int n = mat.size(), m = mat[0].size(), ans = 0;
        for(int i = 0, j = m - 1; i < n && j >= 0; ++ i, -- j) {
            ans += mat[i][i] + mat[i][j];
            if(i == j) {
                ans -= mat[i][i];
            }
        }
        return ans;
    }
};
