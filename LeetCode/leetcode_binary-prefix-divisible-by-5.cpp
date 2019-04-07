/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans(A.size(), false);
        if(A.size() == 0){
            return ans;
        }
        
        int v = 0;
        for(int i = 0; i < A.size(); ++ i, v <<= 1){
            v |= A[i];
            v = v%5;
            if(v == 0) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
