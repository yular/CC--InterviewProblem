/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 0){
            return nums.size();
        }
        
        int ans = 1, cnt = 1;
        for(int i = 1; i < nums.size(); ++ i){
            if(nums[i] > nums[i - 1]){
                ++ cnt;
            } else {
                cnt = 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
