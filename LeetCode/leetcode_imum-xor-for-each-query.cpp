/*
*
* Tag: bit manipulation
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        if(maximumBit < 0) {
            return {};
        }
        
        int mask = (1<<maximumBit) - 1, n = nums.size(), cur = 0;
        for(int i = 0; i < n; ++ i) {
            cur ^= nums[i];
        }
        
        vector<int> ans(n, 0);
        for(int i = n - 1,j = 0; i >= 0; -- i, ++ j) {
            ans[j] = cur^mask;
            cur ^= nums[i];
        }
        return ans;
    }
};
