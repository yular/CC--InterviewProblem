/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3) {
            return false;
        }
        int idx = 1, n = A.size();
        for(int i = 1; i < n - 1; ++ i) {
            if(A[i] == A[i - 1]) {
                return false;
            }
            if(A[i] < A[i - 1]) {
                if(i == 1) {
                    return false;
                }
                break;
            }
            idx = i;
        }
        
        for(int i = idx; i < n - 1; ++ i) {
            if(A[i] <= A[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
