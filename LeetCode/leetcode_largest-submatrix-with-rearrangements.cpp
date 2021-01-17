/*
*
* Tag: Greedy
* Time: O(nmlgm)
* Space: O(nm)
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sum(n, vector<int>(m, 0));
        for(int i = 0; i < m; ++ i) {
            sum[0][i] = matrix[0][i];
            for(int j = 1; j < n; ++ j) {
                if(matrix[j][i] == 0) {
                    continue;
                }
                sum[j][i] = sum[j - 1][i] + matrix[j][i];
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++ i) {
            int col = 0, row = n + 1;
            
            sort(sum[i].begin(), sum[i].end(), greater<int>()); 
            if(sum[i][0] == 0) {
                continue;
            }
            
            int cnt = 0;
            for(int j = 0; j < m; ++ j) {
                if(sum[i][j] == 0) {
                    break;
                }
                ++ cnt;
                
                ans = max(ans, cnt*sum[i][j]);
            }
        }
        return ans;
    }
};
