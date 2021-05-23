/*
*
* Tag: DP
* Time: O(n)
* Space: O(n)
* Credit: https://leetcode.com/problems/stone-game-viii/discuss/1224796/Java-DP-O(N)-short-solution-with-explain-and-train-of-thoughts
*/

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        if(stones.size() < 2) {
            return 0;
        }
        
        int n = stones.size();
        vector<int> sum(n, stones[0]);
        for(int i = 1; i < n; ++ i) {
            sum[i] = sum[i - 1] + stones[i];
        }
        
        vector<int> dp(n, sum[n - 1]);
        for(int i = n - 2; i >= 0; -- i) {
            dp[i] = max(sum[i] - dp[i + 1], dp[i + 1]);
        }
        return dp[1];
    }
};
