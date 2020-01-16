/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        vector<vector<int>> dp(2, vector<int>(3, 0));
        for(int i = 0; i < nums.size(); ++ i){
            for(int j = 0; j < 3; ++ j){
                if(dp[0][j] == 0){
                    continue;
                }
                
                int sum = dp[0][j] + nums[i];
                dp[1][sum%3] = max(dp[1][sum%3], sum);
            }
            
            dp[1][nums[i]%3] = max(dp[1][nums[i]%3], nums[i]);
            for(int j = 0; j < 3; ++ j){
                dp[0][j] = max(dp[0][j], dp[1][j]);
            }
        }
        
        return dp[0][0];
    }
};
