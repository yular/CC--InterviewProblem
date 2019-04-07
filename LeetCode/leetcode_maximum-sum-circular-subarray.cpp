/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
* Reference: https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178517/C%2B%2B-single-pass-O(N)-linear-time-O(1)-constant-space
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 0){
            return 0;
        }
        
        int maxVal = A[0], prevMaxVal = 0, minVal = A[0], prevMinVal = 0, n = A.size(), sum = 0;
        for(int i = 0; i < n; ++ i){
            sum += A[i];
            maxVal = max(maxVal, prevMaxVal = A[i] + max(0, prevMaxVal));
            minVal = min(minVal, prevMinVal = A[i] + min(0, prevMinVal));
        }
        
        return maxVal < 0 ?  maxVal : max(maxVal, sum - minVal);
    }
};
