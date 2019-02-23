/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() < 2){
            return -1;
        }
        
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        
        int leftsum = 0;
        for(int i = 0; i < nums.size(); ++ i){
            if(leftsum == sum - leftsum - nums[i]) {
                return i;
            }
            leftsum += nums[i];
        }
        return -1;
    }
};
