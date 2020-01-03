/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int ans = 0;
        if(A.size() == 0){
            return ans;
        }
        
        vector<vector<int>> largestSubArrSum(2, vector<int>(A.size(), 0));
        int sum = 0, maxSum = 0;
        for(int i = 0; i < A.size(); ++ i) {
            sum += A[i];
            if(i < L - 1) {
                continue;
            }
            if(i >= L) {
                sum -= A[i - L];
            }
            maxSum = max(maxSum, sum);
            largestSubArrSum[0][i] = maxSum;
        }
        sum = 0, maxSum = 0;
        for(int i = A.size() - 1; i >= 0; -- i) {
            sum += A[i];
            if(i > A.size() - L) {
                continue;
            }
            if(i < A.size() - L) {
                sum -= A[i + L];
            }
            maxSum = max(maxSum, sum);
            largestSubArrSum[1][i] = maxSum;
        }
        
        sum = 0, maxSum = 0;
        for(int i = 0; i < A.size() - 1; ++ i){
            sum += A[i];
            if(i < M - 1) {
                continue;
            }
            if(i >= M) {
                sum -= A[i - M];
            }
            maxSum = max(maxSum, sum);
            ans = max(ans, maxSum + largestSubArrSum[1][i + 1]);
        }     
        sum = 0, maxSum = 0;
        for(int i = A.size() - 1; i >= 1; -- i){
            sum += A[i];
            if(i > A.size() - M) {
                continue;
            }
            if(i < A.size() - M) {
                sum -= A[i + M];
            }
            maxSum = max(maxSum, sum);
            ans = max(ans, maxSum + largestSubArrSum[0][i - 1]);
        }
        return ans;
    }
};
