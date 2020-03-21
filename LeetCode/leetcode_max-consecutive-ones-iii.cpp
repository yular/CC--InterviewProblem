/*
*
* Tag: Sliding Windows
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = -1, r = 0, zeroCnt = 0, ans = 0;
        for(; r < A.size(); ++ r) {
            if(A[r] == 0) {
                ++ zeroCnt;
            }
            
            while(zeroCnt > K) {
                ++ l;
                if(A[l] == 0) {
                    -- zeroCnt;
                }
            }
            
            ans = max(ans, r - l);
        }
        return ans;
    }
};
