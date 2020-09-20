/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        if(p < 1) {
            return -1;
        }
        if(p == 1) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0]%p == 0? 0 : -1;
        }
        
        int mod = 0;
        for(int num : nums){
            mod = (mod + num)%p;
        }
        if(mod == 0) {
            return 0;
        }
        
        int cur = 0, n = nums.size(), ans = n;
        unordered_map<int, int> modDict = {{0, -1}};
        for(int i = 0; i < n; ++ i) {
            cur = (cur + nums[i])%p;
            modDict[cur] = i;
            int res = (p + cur - mod)%p;
            if(modDict.count(res)) {
                ans = min(ans, i - modDict[res]);
            }
        }    
        return ans == n? -1 : ans;
    }
};
