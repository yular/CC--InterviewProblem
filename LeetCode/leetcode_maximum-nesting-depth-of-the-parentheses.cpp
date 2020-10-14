/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxDepth(string s) {
        if(s.size() < 2) {
            return 0;
        }
        
        int ans = 0, cnt = 0;
        for(char c : s) {
            if(c == '(') {
                ++ cnt;
            } else if(c == ')') {
                -- cnt;
            }
            
            ans = max(ans, cnt);
        }
        return ans;
    }
};
