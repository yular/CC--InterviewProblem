/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int n = nums.size(), oddSum = 0, evenSum = 0;
        vector<vector<int>> sums(2, vector<int>(n, 0));
        for(int i = n - 1; i >= 0; -- i) {
            if(i%2 == 0) {
                evenSum += nums[i];
            } else {
                oddSum += nums[i];
            }
            sums[0][i] = evenSum;
            sums[1][i] = oddSum;
        }
        
        oddSum = 0, evenSum = 0;
        int ans = 0;
        for(int i = 0; i < n; ++ i) {
            int actualOddSum = oddSum, actualEvenSum = evenSum;
            if(i < n - 1) {
                actualOddSum += sums[0][i + 1];
                actualEvenSum += sums[1][i + 1];
            }
            if(actualOddSum == actualEvenSum) {
                ++ ans;
            }
            if(i%2 == 0) {
                evenSum += nums[i];
            } else {
                oddSum += nums[i];
            }
        }
        return ans;
    }
};
