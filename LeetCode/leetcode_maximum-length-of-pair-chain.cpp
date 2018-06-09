/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0;
        if(pairs.size() == 0){
            return ans;
        }
        
        sort(pairs.begin(), pairs.end(), cmp);
        
        int n = pairs.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; ++ i){
            for(int j = 0; j < i; ++ j){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
private:
    struct chainComparator{
        bool operator() (const vector<int> &a, const vector<int> &b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        }
    }cmp;
};
