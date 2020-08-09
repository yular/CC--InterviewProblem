/*
*
* Tag: stack ( Data Structure )
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string makeGood(string s) {
        if(s.size() < 2) {
            return s;
        }
        
        int n = s.size(), top = 0;
        vector<char> stk(n);
        for(int i = 0; i < n; ++ i) {
            if(top > 0 && tolower(stk[top - 1]) == tolower(s[i])) {
                if(stk[top - 1] != s[i]) {
                    -- top;
                    continue;
                }
            }
            
            stk[top ++] = s[i];
        }
        
        string ans = "";
        for(int i = 0; i < top; ++ i) {
            ans += stk[i];
        }
        return ans;
    }
};
