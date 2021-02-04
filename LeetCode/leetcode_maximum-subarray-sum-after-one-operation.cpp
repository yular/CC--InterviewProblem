/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0]*nums[0];
        }
        
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        long long sum = 0;
        for(int i = 0; i < n; ++ i) {
            if(sum + nums[i] > nums[i]){
                sum += nums[i];
            }else{ 
                sum = nums[i]; 
            }
            dp[0][i] = sum;
        }
        
        sum = 0;
        for(int i = n - 1; i >= 0; -- i) {
            if(sum + nums[i] > nums[i]){
                sum += nums[i];
            }else{ 
                sum = nums[i]; 
            }
            dp[1][i] = sum;
        }
        
        long long ans = 0;
        for(int i = 0; i < n; ++ i) {
            long long sum = nums[i]*nums[i];
            long long v = sum;
            ans = max(ans, sum);
            if(i > 0) {
                ans = max(ans, v + dp[0][i - 1]);
                sum += dp[0][i - 1];
            }
            ans = max(ans, sum);
            if(i < n - 1) {
                ans = max(ans, v + dp[1][i + 1]);
                sum += dp[1][i + 1];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
