/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        if(A.size() == 0) {
            return 0;
        }
        
        sort(A.begin(), A.end());
        
        int n = A.size();
        unordered_map<long long,int> dict;
        for(int i = 0; i < n; ++ i) {
            dict[A[i]] = i;
        }
        
        vector<long long> dp(n, 1);
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < i; ++ j) {
                if(A[i]%A[j] != 0 || dict.count(A[i]/A[j]) == 0) {
                    continue;
                }
                
                int idx = dict[A[i]/A[j]];
                dp[i] = (dp[i] + (dp[j]*dp[idx])%MOD)%MOD;
            }
        }
        
        long long ans = 0;
        for(int i = 0; i < n; ++ i) {
            ans = (ans + dp[i])%MOD;
        }
        return ans;
    }
};
