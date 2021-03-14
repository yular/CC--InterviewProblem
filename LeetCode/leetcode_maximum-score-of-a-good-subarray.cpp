/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
* Credit: https://leetcode.com/problems/maximum-score-of-a-good-subarray/discuss/1108863/C%2B%2B-simple-two-pointers-100
*/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        if(nums.size() == 0 || k < 0 || k >= nums.size()) {
            return 0;
        }
        
        int ans = 0, n = nums.size(), curVal = nums[k];
        for(int l = k, r = k; l > 0 || r < n;) {
            while(l > 0 && nums[l - 1] >= curVal) {
                -- l;
            }
            while(r < n - 1 && nums[r + 1] >= curVal) {
                ++ r;
            }
            ans = max(ans, curVal*(r - l + 1));
            
            if(l <= 0 || (r < n - 1 && nums[r + 1] >= nums[l - 1]) ) {
                curVal = nums[++ r];
            } else if(l > 0) {
                curVal = nums[-- l];
            }
        }
        return ans;
    }
};
