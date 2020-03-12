/*
*
* Tag: Data Structure, Stack
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    string reverseParentheses(string s) {
        if(s.size() == 0) {
            return s;
        }
        
        vector<char> stk(s.size(), 0), tmp(s.size(), 0);
        int top = 0, tmp_idx = 0;
        for(char c : s) {
            if(c != ')') {
                stk[top ++] = c;
                continue;
            }
            
            tmp_idx = 0;
            while(top > 0 && stk[top - 1] != '(') {
                tmp[tmp_idx ++] = stk[top - 1];
                -- top;
            }
            if(top > 0) {
                -- top;
            }
            
            for(int i = 0; i < tmp_idx; ++ i){
                stk[top ++] = tmp[i];
            }
        }
        
        string ans = "";
        for(int i = 0; i < top; ++ i){
            ans += stk[i];
        }
        return ans;
    }
};
