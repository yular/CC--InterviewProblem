/*
*
* Tag: DP
* Time: O(n) => O(n^2)
* Space: O(n)
*/

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        if(digits.size() == 0) {
            return "";
        }
        
        sort(digits.begin(), digits.end(), greater<int>());
        
        string lastDp[3] = {"", "", ""};
        for(int d : digits) {
            string dp[3] = {"", "", ""};
            int v = d%3;
            dp[v] = lastDp[0] + to_string(d);
            for(int i = 0; i < 3; ++ i) {
                if(lastDp[i] == "") {
                    continue;
                }
                
                int nxt = (v + i)%3;
                dp[nxt] = lastDp[i] + to_string(d);
            }
            
            for(int i = 0; i < 3; ++ i) {
                if(dp[i].size() > lastDp[i].size()) {
                    lastDp[i] = dp[i];
                } else if(dp[i].size() == lastDp[i].size() && dp[i] > lastDp[i]) {
                    lastDp[i] = dp[i];
                }
            }
        }
        if(lastDp[0] == "") {
            return "";
        }
        
        if(lastDp[0][0] == '0') {
            return "0";
        }
        return lastDp[0];
    }
};
