/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        if(A.size() == 0) {
            return {};
        }
        
        vector<int> ans(A.begin(), A.end());
        bool isAsc = true;
        int idx = A.size() - 1, bnd = 0;
        for(; idx > 0; -- idx) {
            if(A[idx - 1] > A[idx]) {
                bnd = idx - 1;
                isAsc = false;
                break;
            }
        }
        if(isAsc) {
            return ans;
        }
        
        int targIdx = idx, targVal = A[idx];
        for(int i = A.size() - 1; i > bnd; -- i) {
            if(A[i] < A[bnd] && A[i] >= targVal) {
                if(A[i] == targVal) {
                    targIdx = min(targIdx, i);
                    continue;
                }
                
                targVal = A[i];
                targIdx = i;
            }
        }
        swap(ans[bnd], ans[targIdx]);
        return ans;
    }
};
