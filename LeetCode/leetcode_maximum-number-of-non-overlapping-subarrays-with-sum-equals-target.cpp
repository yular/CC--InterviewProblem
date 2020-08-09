/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int ans = 0, n = nums.size();
        unordered_map<long long,int> sumIdx;
        vector<int> dp(n, 0);
        sumIdx[0] = -1;
        long long sum = 0;
        for(int i = 0; i < n; ++ i) {
            if(i > 0) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
            
            sum += nums[i];
            long long key = sum - target;
            if(sumIdx.count(key) > 0) {
                int res = 0;
                if(sumIdx[key] != -1) {
                    res = dp[sumIdx[key]];
                }
                
                dp[i] = max(dp[i], res + 1);
            }
            
            sumIdx[sum] = i;
        }
        return dp[n - 1];
    }
};
