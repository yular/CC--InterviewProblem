/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        }
        
        int n = nums.size(), ans = 0;
        for(int i = 1; i < n; ++ i) {
            if(nums[i - 1] < nums[i]) {
                continue;
            }
            ans += (nums[i - 1] - nums[i] + 1);
            nums[i] = nums[i - 1] + 1;
        }
        return ans;
    }
};
