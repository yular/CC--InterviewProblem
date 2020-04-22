/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, cost = 0, n = s.size();
        for(int l = 0, r = 0; r < n; ++ r){
            cost += abs(s[r] - t[r]);
            while(cost > maxCost && l <= r) {
                cost -= abs(s[l] - t[l]);
                ++ l;
            }
            
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
