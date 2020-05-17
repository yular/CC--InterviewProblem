/*
*
* Tag: brute force
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 0) {
            return 0;
        }
        
        int ans = 1, cnt = 1;
        for(int i = 1; i < s.size(); ++ i) {
            if(s[i] != s[i - 1]) {
                cnt = 0;
            }
            ++ cnt;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
