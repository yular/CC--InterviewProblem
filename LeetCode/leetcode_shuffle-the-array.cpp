/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        if(nums.size() != 2*n || n < 2) {
            return nums;
        }
        
        vector<int> ans = nums;
        for(int idx = 0, i = 0, j = n; i < n; ++ i, ++ j, idx += 2) {
            ans[idx] = nums[i];
            ans[idx + 1] = nums[j];
        }
        return ans;
    }
};
