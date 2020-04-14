/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        if(k == 0) {
            return nums[0];
        }
        
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; ++ i) {
            if(i == n - 1) {
                ans = nums[i] + k;
                break;
            }
            if(nums[i] + k < nums[i + 1]){
                ans = nums[i] + k;
                break;
            }
            k -= (nums[i + 1] - nums[i] - 1);
        }
        return ans;
    }
};
