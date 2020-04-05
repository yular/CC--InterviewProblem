/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        if(nums.size() < 2) {
            return nums;
        }
        
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        
        vector<int> ans;
        int curSum = 0;
        for(int i = nums.size() - 1; i >= 0; -- i) {
            curSum += nums[i];
            ans.push_back(nums[i]);
            if(curSum*2 > sum) {
                break;
            }
        }
        return ans;
    }
};
