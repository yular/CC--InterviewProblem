/*
*
* Tag: Math
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        if(mat.size() == 0 || k == 0) {
            return mat;
        }
        
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> sum(n, vector<int>(m, 0)), ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                sum[i][j] = mat[i][j];
                if(j > 0) {
                    sum[i][j] += sum[i][j - 1];
                }
            }
            if(i == 0){
                continue;
            }
            
            for(int j = 0; j < m; ++ j) {
                sum[i][j] += sum[i - 1][j];
            }
        }
        
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                int btn_i = i + k, btn_j = j + k, top_i = i - k, top_j = j - k;
                btn_i = min(btn_i, n - 1), btn_j = min(btn_j, m - 1);
                top_i = max(top_i, 0), top_j = max(top_j, 0);
                                
                 int tmp = sum[btn_i][btn_j];
                if(top_i > 0) {
                    tmp -= sum[top_i - 1][btn_j];
                }
                if(top_j > 0) {
                    tmp -= sum[btn_i][top_j - 1];
                }
                if(top_i > 0 && top_j > 0) {
                    tmp += sum[top_i - 1][top_j - 1];
                }
                
                ans[i][j] = tmp;
            }
        }
        return ans;
    }
};
