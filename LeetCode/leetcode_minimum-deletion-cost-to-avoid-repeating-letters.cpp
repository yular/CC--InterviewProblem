/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        if(s.size() < 2 || s.size() != cost.size()) {
            return 0;
        }
        
        int ans = 0;
        for(int i = 1; i < s.size(); ++ i){
            if(s[i] != s[i - 1]) {
                continue;
            }
            
            int maxVal = cost[i - 1], sum = cost[i - 1];
            while(i < s.size() && s[i] == s[i - 1]) {
                maxVal = max(maxVal, cost[i]);
                sum += cost[i];
                ++ i;
            }
            ans += (sum - maxVal);
        }
        return ans;
    }
};
