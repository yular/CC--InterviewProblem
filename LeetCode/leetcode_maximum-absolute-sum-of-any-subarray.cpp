/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int ans = 0, minSum = 0, maxSum = 0;
        for(int i = 0; i < nums.size(); ++ i) {
            minSum = min(0, minSum + nums[i]);
            maxSum = max(0, maxSum + nums[i]);
            
            ans = max(ans, max(-minSum, maxSum));
        }
        return ans;
    }
};
