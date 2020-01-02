/*
*
* Tag: Math
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int mid = nums.size()/2;
        return nums.size()%2 == 1 ? nums[mid] == target : nums[mid - 1] == target && nums[mid] == target;
    }
};
