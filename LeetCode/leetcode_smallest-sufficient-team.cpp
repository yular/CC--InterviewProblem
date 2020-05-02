/*
*
* Tag: DP
* Time: O(nm)
* Space: O(nm)
*/

class Solution {
private:
    const long long BND = 1L<<62;
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        if(req_skills.size() == 0 || people.size() == 0) {
            return {};
        }
        
        unordered_map<string,int> dict;
        int mask = 1;
        for(string skill : req_skills) {
            dict[skill] = mask;
            mask <<= 1;
        }
        
        int m = people.size();
        vector<long long> pskills(m, 0);
        for(int i = 0; i < m; ++ i) {
            long long mask = 0;
            for(string skill : people[i]) {
                mask |= dict[skill];
            }
            pskills[i] = mask;
        }
        
        int n = mask - 1;
        vector<pair<int, long long>> dp(n + 1, make_pair(m + 10, 0));
        dp[0].first = 0;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                if((i&pskills[j]) == pskills[j]) {
                    continue;
                }
                
                int v = (i|pskills[j]);
                if(dp[v].first > dp[i].first + 1) {
                    dp[v].first = dp[i].first + 1;
                    dp[v].second = (dp[i].second|(1L<<j));
                }
            }
        }
        
        vector<int> ans;
        for(long long p = 1, i = 0; p < BND && i < people.size(); p <<= 1, ++ i) {
            if((dp[n].second&p) > 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
