/*
*
* Tag: Greedy
* Time: O(mn^2)
* Space: O(m)
*/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.size() == 0){
            return 0;
        }
        
        int ans = 0, n = A.size(), m = A[0].size();
        vector<bool> vis(m, false);
        for(int i = 1; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(vis[j] || A[i - 1][j] == A[i][j]) {
                    continue;
                }
                
                if(A[i - 1][j] > A[i][j]) {
                    i = 0;
                    ++ ans;
                    vis[j] = true;
                }
                break;
            }            
        }
        return ans;
    }
};
