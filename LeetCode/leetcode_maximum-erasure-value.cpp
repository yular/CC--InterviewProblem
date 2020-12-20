/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        
        vector<bool> vis(100010, false);
        vis[nums[0]] = true;
        int ans = nums[0], n = nums.size(), tmp = nums[0];
        for(int i = 1, l = 0; i < n; ++ i) {
            while(vis[nums[i]] && l <= i) {
                vis[nums[l]] = false;
                tmp -= nums[l];
                ++ l;
            }
            tmp += nums[i];
            ans = max(ans, tmp);
            vis[nums[i]] = true;
        }
        return ans;
    }
};
