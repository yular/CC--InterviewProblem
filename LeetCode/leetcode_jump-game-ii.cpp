/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1){
            return 0;
        }
        
        int startIdx = 0, reach = nums[0];
        int step = 0;
        while(startIdx < nums.size()){
            step ++;
            if(reach >= nums.size() - 1){
                return step;
            }
            
            int maxReach = INT_MIN;
            for(int i = startIdx; i <= reach; i ++){
                if(nums[i] + i > maxReach){
                    maxReach = nums[i] + i;
                }
            }
            startIdx = reach + 1;
            reach = maxReach;
        }
        return step;
    }
};
