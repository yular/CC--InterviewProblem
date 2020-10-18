/*
*
* Tag: DP
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        if(scores.size() != ages.size() || scores.size() == 0 ) {
            return -1;
        }
        
        int n = scores.size();
        vector<vector<int>> teams(n, vector<int>(2, 0));
        for(int i = 0; i < n; ++ i) {
            teams[i] = {ages[i], scores[i]};
        }
        
        sort(teams.begin(), teams.end(), cmp);
        
        vector<int> dp(n, 0);
        dp[0] = teams[0][1];
        int ans = dp[0];
        for(int i = 1; i < n; ++ i) {
            dp[i] = teams[i][1];
            for(int j = 0; j < i; ++ j) {
                if(teams[j][0] < teams[i][0] && teams[j][1] > teams[i][1]) {
                    continue;
                }
                
                dp[i] = max(dp[i], dp[j] + teams[i][1]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
private:
    struct comparator {
        bool operator() (vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        }
    }cmp;
};
