/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        if(nums.size() < 4) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n-1]*nums[n-2] - nums[0]*nums[1];
    }
};
