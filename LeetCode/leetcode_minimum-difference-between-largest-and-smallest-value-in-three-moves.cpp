/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() < 5) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int ans = INT_MAX, n = nums.size() - 1;
        for(int i = 0; i <= 3; ++ i) {
            for(int j = 0; i + j <= 3; ++ j) {
                ans = min(ans, nums[n - j] - nums[i]);
            }
        }
        return ans;
    }
};
