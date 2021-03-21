/*
*
* Tag: Brute Force
* Time: O(n^2)
* Space: O(1)
*/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; ++ i) {
            int sum = nums[i];
            for(int j = i + 1; j < n; ++ j) {
                if(nums[j] <= nums[j - 1]) {
                    break;
                }
                sum += nums[j];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
