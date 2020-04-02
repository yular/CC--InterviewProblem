/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, lcnt = 0;
        for(int i = 0; i < s.size(); ++ i) {
            if(s[i] == 'L') {
                ++ lcnt;
            } else {
                -- lcnt;
            }
            if(lcnt == 0) {
                ++ ans;
            }
        }
        return ans;
    }
};
