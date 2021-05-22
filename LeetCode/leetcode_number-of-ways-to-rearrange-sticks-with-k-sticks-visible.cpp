/*
*
* Tag: DP
* Time: O(nk)
* Space: O(nk)
* Credit: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/discuss/1221799/C%2B%2B-or-O(n*k)-or-10-lines-code-or-Fully-Commented-solution
*/

class Solution {
private:
    long long dp[1001][1001];
public:
    int rearrangeSticks(int n, int k) {
        memset(dp, -1 ,sizeof(dp));
        return dfs(n, k);
    }
private:
    long long MOD = 1e9+7;
    
    long long dfs(long long n, int k) {
        if(k == 0 || k > n) {
            return 0;
        }
        if(n == 2) {
            return 1;
        }
        if(dp[n][k] != -1) {
            return dp[n][k];
        }
        
        long long ans = 0;
        ans += 1 * dfs(n - 1, k - 1);
        ans = (ans + (n - 1) * dfs(n - 1, k) % MOD) % MOD;
        
        return dp[n][k] = ans;   
    }
};
