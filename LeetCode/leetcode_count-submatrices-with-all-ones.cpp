/*
*
* Tag: DP + Sliding Window
* Time: O(nm^2)
* Space: O(nm)
*/

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        if(mat.size() == 0) {
            return 0;
        }
        
        int n = mat.size(), m = mat[0].size(), ans = 0;
        vector<vector<int>> colSum(n, vector<int>(m, 0));
        for(int i = 0; i < m; ++ i) {
            for(int j = 0; j < n; ++ j) {
                if(mat[j][i] == 0) {
                    continue;
                }
                
                int v = 1;
                if(j > 0) {
                    v += colSum[j - 1][i];
                }
                colSum[j][i] = v;
                
                int minlen = v;
                for(int k = i; k >= 0; -- k) {
                    if(colSum[j][k] == 0) {
                        break;
                    }
                    minlen = min(minlen, colSum[j][k]);
                    ans += minlen;
                }
            }
        }
        return ans;
    }
};
