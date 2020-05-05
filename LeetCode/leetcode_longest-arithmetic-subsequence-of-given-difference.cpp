/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        if(arr.size() == 0) {
            return 0;
        }
        
        unordered_map<int,int> dp;
        int ans = 0, n = arr.size();
        dp[arr[0]] = 1;
        for(int i = 1; i < n; ++ i) {
            int prev = arr[i] - difference, res = 1;
            res += dp[prev];           
            dp[arr[i]] = max(dp[arr[i]], res);
            ans = max(ans, res);
        }
        return ans;
    }
};
