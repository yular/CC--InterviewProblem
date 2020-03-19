/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int fixedPoint(vector<int>& A) {
        if(A.size() == 0) {
            return -1;
        }
        
        for(int i = 0; i < A.size(); ++ i) {
            if(A[i] == i) {
                return i;
            }
        }
        return -1;
    }
};
