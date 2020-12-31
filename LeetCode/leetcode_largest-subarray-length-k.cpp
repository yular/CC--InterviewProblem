/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(k)
*/

class Solution {
public:
    vector<int> largestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n) {
            return nums;
        }
        
        vector<int> ans(k);
        int maxV = 0, maxId = 0;
        for(int i = 0; i + k <= n; ++ i) {
            if(nums[i] > maxV) {
                maxV = nums[i];
                maxId = i;
            }
        }
        
        for(int i = maxId, len = 0; len < k && i < n; ++ i, ++ len) {
            ans[len] = nums[i];
        }
        return ans;
    }
};
