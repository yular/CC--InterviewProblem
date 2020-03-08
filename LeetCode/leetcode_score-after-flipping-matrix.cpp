/*
*
* Tag: Greedy
* Time: O(nm)
* Space: O(1)
*/

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if(A.size() == 0) {
            return 0;
        }
        
        int n = A.size(), m = A[0].size();
        for(int i = 0; i < n; ++ i){
            if(A[i][0] == 1) {
                continue;
            }
            
            for(int j = 0; j < m; ++ j){
                A[i][j] ^= 1;
            }
        }
        
        for(int i = 1; i < m; ++ i) {
            int cntOne = 0;
            for(int j = 0; j < n; ++ j){
                cntOne += A[j][i];
            }
            
            if(cntOne*2 >= n) {
                continue;
            }
            
            for(int j = 0; j < n; ++ j){
                A[j][i] ^= 1;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++ i){
            int v = 0, mask = 1;
            for(int j = m - 1; j >= 0; -- j, mask <<= 1){
                if(A[i][j] == 0){
                    continue;
                }
                v |= mask;
            }
            ans += v;
        }
        
        return ans;
    }
};
