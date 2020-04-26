/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxScore(string s) {
        if(s.size() < 2) {
            return 0;
        }
        
        int cnt1 = 0, n = s.size();
        for(int i = n - 1; i >= 0; -- i) {
            if(s[i] == '1') {
                ++ cnt1;
            }
        }
        
        int cnt0 = 0, ans = 0;
        for(int i = 0; i < n - 1; ++ i) {
            if(s[i] == '0') {
                ++ cnt0;
            } else {
                -- cnt1;
            }
            
            ans = max(ans, cnt0 + cnt1);
        }
        return ans;
    }
};
