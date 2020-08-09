/*
*
* Tag: Stack ( Data Structure )
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minInsertions(string s) {
        if(s.size() == 0) {
            return 0;
        }
        if(s.size() < 3) {
            return 3 - s.size();
        }
        
        int top = 0, n = s.size(), ans = 0;
        vector<char> stk(n);
        for(int i = 0; i < n; ++ i) {
            if(top == 0 || s[i] == '(') {
                if(top > 0 && stk[top - 1] == ')') {
                    -- top;
                    ans += 2;
                }
                stk[top ++] = s[i];
                continue;
            }
            
            if(stk[top - 1] == '(') {
                if(i == n - 1 || s[i + 1] != ')') {
                    ++ ans;
                } else {
                    ++ i;
                }
            } else {
                ++ ans;
            }
            
            -- top;
        }
        
        ans += 2*top;
        return ans;
    }
};
