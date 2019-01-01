/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size() == 0){
            return A;
        }
        int oddIdx = 0;
        for(int evenIdx = 0; evenIdx < A.size() && oddIdx < A.size(); ++ evenIdx){
            if(A[evenIdx]%2 == 0){
                continue;
            }
            if(oddIdx < evenIdx){
                oddIdx = evenIdx + 1;
            }
            while(oddIdx < A.size() && A[oddIdx]%2 == 1){
                ++ oddIdx;
            }
            if(oddIdx < A.size()){
                swap(A[evenIdx], A[oddIdx]);
            }
        }
        return A;
    }
};
