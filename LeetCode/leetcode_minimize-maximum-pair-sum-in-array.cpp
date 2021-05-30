/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(lgn)
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        if(nums.size()%2 == 1) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int ans = 0, n = nums.size(), m = nums.size()/2;
        for(int i = 0; i < m; ++ i) {
            ans = max(ans, nums[i] + nums[n - 1 - i]);
        }
        return ans;
    }
};
