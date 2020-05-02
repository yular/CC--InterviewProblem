/*
*
* Tag: DP
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    int d[3] = {1, 7, 30};
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if(days.size() == 0 || costs.size() == 0) {
            return 0;
        }
        
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < days[0]; ++ i) {
            dp[i] = 0;
        }
        
        int n = days.size();
        for(int i = days[0], k = 0; i <= days[n - 1]; ++ i) {
            if(i < days[k]) {
                dp[i] = dp[i - 1];
                continue;
            }
            if(i == days[k]) {
                ++ k;
            }
            for(int j = 0; j < 3; ++ j) {
                int last = max(0, i - d[j]);
                dp[i] = min(dp[i], dp[last] + costs[j]);
            }
        }
        return dp[days[n - 1]];
    }
};
