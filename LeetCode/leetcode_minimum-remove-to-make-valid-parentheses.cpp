/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.size() == 0){
            return s;
        }
        
        string ans = "";
        vector<bool> vis(s.size(), false);
        vector<int> stk(s.size());
        int top = 0;
        for(int i = 0; i < s.size(); ++ i){
            if(s[i] >= 'a' && s[i] <= 'z') {
                vis[i] = true;
                continue;
            }
            
            if(top == 0 || s[i] == '(') {
                stk[top ++] = i;
                continue;
            }
            
            if(s[stk[top - 1]] == '('){
                vis[stk[top - 1]] = true;
                vis[i] = true;
                -- top;
            }
        }
        
        for(int i = 0; i < s.size(); ++ i){
            if(vis[i]) {
                ans += s[i];
            }
        }
        return ans;
    }
};
