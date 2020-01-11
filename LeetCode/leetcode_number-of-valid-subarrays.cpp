/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int ans = 0;
        if(nums.size() == 0){
            return ans;
        }
        
        stack<int> stk;
        for(int i = 0; i <= nums.size(); ++ i){
            int curVal = i == nums.size()? -1 : nums[i];
            if(stk.empty()){
                stk.push(i);
                continue;
            }
            while(!stk.empty()) {
                if(curVal >= nums[stk.top()]){
                    break;
                }
                ans += (i - stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
