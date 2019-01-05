/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(1)
*/
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans = 0;
        if(A.size() == 0 || A[0].size() == 0){
            return ans;
        }
        
        int numOfCols = A[0].size();
        for(int i = 0; i < numOfCols; ++ i){
            for(int j = 1; j < A.size(); ++ j){
                if(A[j][i] < A[j - 1][i]){
                    ++ ans;
                    break;
                }
            }
        }
        return ans;
    }
};
