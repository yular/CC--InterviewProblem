/*
*
* Tag: DP
* Time: O(Target) (not strict)
* Space: O(Target)
*/

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        if(target == 0) {
            return "0";
        }
        
        vector<string> dp(target + 1, "");
        for(int i = 0; i < 9; ++ i) {
            string cur = to_string(i + 1);
            int idx = cost[i];
            if(idx <= target && isLarger(cur, dp[idx])) {
                dp[idx] = cur;
            }
        }
        
        for(int i = 1; i <=  target; ++ i) {
            for(int j = 0; j < 9; ++ j) {
                int idx = i - cost[j];
                if(cost[j] >= i || dp[idx].size() == 0) {
                    continue;
                }
                
                string cur = dp[idx] + to_string(j + 1);
                if(isLarger(cur, dp[i])) {
                    dp[i] = cur;
                }
            }
        }
        return dp[target] == "" ? "0" : dp[target];
    }
private:
    bool isLarger(string a, string b) {
        if(a.size() < b.size()) {
            return false;
        }
        if(a.size() > b.size()) {
            return true;
        }
        return a > b;
    }
};
