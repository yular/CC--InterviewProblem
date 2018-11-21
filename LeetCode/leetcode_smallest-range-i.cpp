/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxVal = INT_MIN, minVal = INT_MAX;
        for(int i = 0; i < A.size(); ++ i){
            maxVal = max(maxVal, A[i]);
            minVal = min(minVal, A[i]);
        }
        return maxVal - minVal < 2*K ? 0 : maxVal - minVal - 2*K;
    }
};
