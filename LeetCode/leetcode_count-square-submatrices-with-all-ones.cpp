/*
*
* Tag: Brute Force
* Time: O(n^3)
* Space: O(n^2)
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sumMtx(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(matrix[i][j] == 0) {
                    continue;
                }
                
                sumMtx[i][j] = 1;
                if(j > 0) {
                    sumMtx[i][j] += sumMtx[i][j - 1];
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(i > 0){
                    sumMtx[i][j] += sumMtx[i - 1][j];
                }
                
                if(matrix[i][j] == 0) {
                    continue;
                }
                ++ ans;
                
                for(int l = 2; i - l + 1 >= 0 && j - l + 1 >= 0; ++ l) {
                    int sum = sumMtx[i][j];
                    if(i + 1 - l > 0) {
                        sum -= sumMtx[i - l][j];
                    }
                    if(j + 1 - l > 0) {
                        sum -= sumMtx[i][j - l];
                    }
                    if(i + 1 - l > 0 && j + 1 - l > 0) {
                        sum += sumMtx[i - l][j - l];
                    }
                    if(sum != l*l){
                        break;
                    }
                    ++ ans;
                }
            }
        }
        
        return ans;
    }
};
