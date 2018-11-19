/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() == 0){
            return true;
        }
        return isNonDecreasingArray(A) || isNonIncreasingArray(A);
    }
private:
    bool isNonDecreasingArray(vector<int>& A){
        for(int i = 1; i < A.size(); ++ i){
            if(A[i] < A[i - 1]){
                return false;
            }
        }
        return true;
    }
    
    bool isNonIncreasingArray(vector<int>& A){
        for(int i = 1; i < A.size(); ++ i){
            if(A[i] > A[i - 1]){
                return false;
            }
        }
        return true;
    }
};
