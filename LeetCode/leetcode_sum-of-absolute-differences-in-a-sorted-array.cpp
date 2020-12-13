/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        if(nums.size() == 0) {
            return {};
        }
        
        int n = nums.size(), rSum = 0;
        for(int i = n - 1; i >= 0; -- i) {
            rSum += nums[i];
        }
        
        vector<int> ans(n, 0);
        int lSum = 0;
        for(int i = 0; i < n; ++ i) {
            rSum -= nums[i];
            ans[i] = i*nums[i] - lSum + rSum - (n - 1 - i)*nums[i];
            lSum += nums[i];
        }
        return ans;
    }
};
