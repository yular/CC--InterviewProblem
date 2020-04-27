/*
*
* Tag: DP
* Time: O(nlgk)
* Space: O(k)
*/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int n = nums.size(), ans = INT_MIN, sum = 0;
        vector<int> dp(n, 0);
        map<int,int> maxVal;
        for(int l = 0, r = 0; r < n; ++ r) {
            sum = nums[r];
            if(r - l > k) {
                -- maxVal[dp[l]];
                if(maxVal[dp[l]] == 0) {
                    maxVal.erase(dp[l]);
                }
                ++ l;
            }
            if(maxVal.size() > 0) {
                auto it = maxVal.rbegin();
                sum += it->first;
            }
            
            dp[r] = max(nums[r], sum);
            ++ maxVal[dp[r]];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};
