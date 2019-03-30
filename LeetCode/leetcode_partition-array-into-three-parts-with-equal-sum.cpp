/*
*
* Tag:
* Time:
* Space:
*/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if(A.size() < 3) {
            return false;
        }
        
        int sum = 0;
        for(int a : A){
            sum += a;
        }
        if(sum%3 != 0){
            return false;
        }
        
        int subSum = sum/3, sufSum = 0;
        vector<int> suffixSum(A.size(), 0);
        queue<int> idxQ;
        for(int i = A.size() - 1; i >= 0; -- i){
            sufSum += A[i];
            suffixSum[i] = sufSum;
            if(sufSum == subSum){
                idxQ.push(i);
            }
        }
        
        if(idxQ.empty()){
            return false;
        }
        
        int curSum = 0;
        for(int i = 0; i < A.size() - 2; ++ i){
            curSum += A[i];
            if(i >= idxQ.front()){
                idxQ.pop();
            }
            if(idxQ.empty()) {
                break;
            }
            
            int idx = idxQ.front();
            if(curSum == subSum && suffixSum[i + 1] == 2*subSum && idx > i + 1 ) {
                return true;
            }
        }
        return false;
    }
};
