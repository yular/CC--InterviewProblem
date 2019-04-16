/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n^2)
*/
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if(A.size() < 2){
            return A.size();
        }
        
        int ans = 0;
        vector<unordered_map<int,int>> dp(A.size());
        for(int i = 1; i < A.size(); ++ i){
            for(int j = 0; j < i; ++ j){
                int diff = A[i] - A[j];
                int prevlen = dp[j].count(diff) == 0? 1 : dp[j][diff];
                dp[i][diff] = max(dp[i][diff], prevlen + 1);
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};
