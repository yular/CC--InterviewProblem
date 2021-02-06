/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        vector<int> numCnt(110, 0);
        for(int num : nums) {
            ++ numCnt[num];
        }
        
        int ans = 0;
        for(int i = 0; i < nums.size(); ++ i) {
            if(numCnt[nums[i]] == 1) {
                ans += nums[i];
            }
        }
        return ans;
    }
};
