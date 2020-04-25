/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if(arr.size() == 0) {
            return 0;
        }
        
        int ans = INT_MIN, n = arr.size(), sum = 0;
        vector<int> dp(arr.size(), 0);
        for(int i = n - 1; i >= 0; -- i) {
            sum += arr[i];
            dp[i] = max(sum, arr[i]);
            if(sum < 0) {
                sum = 0;
            }
            ans = max(ans, dp[i]);
        }
        
        sum = 0;
        for(int i = 0; i < n - 1; ++ i) {
            sum += arr[i];
            if(i <= n - 3) {
                ans = max(ans, sum + dp[i + 2]);
            }
            if(sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};
