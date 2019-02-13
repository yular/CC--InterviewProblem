/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(1)
*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.size() == 0){
            return A;
        }
        
        vector<vector<int>> ans(A[0].size(), vector<int>(A.size()));
        for(int i = 0; i < A.size(); ++ i){
            for(int j = 0; j < A[i].size(); ++ j){
                ans[j][i] = A[i][j];
            }
        }
        return ans;
    }
};
