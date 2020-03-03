/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        if(A.size() == 0){
            return -1;
        }
        
        int minVal = A[0];
        for(int i = 1; i < A.size(); ++ i){
            minVal = min(minVal, A[i]);
        }
        
        int sum = 0;
        while(minVal > 0){
            sum += minVal%10;
            minVal /= 10;
        }
        return (sum&1) == 0? 1 : 0;
    }
};
