/*
*
* Tag: Data Structure
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string removeDuplicates(string S) {
        if(S.size() < 2) {
            return S;
        }
        
        vector<char> stk(S.size(), 0);
        int top = 0;
        for(char w : S) {
            if(top == 0) {
                stk[top ++] = w;
                continue;
            }
            char cur = stk[top - 1];
            if(cur == w) {
                -- top;
                continue;
            }
            stk[top ++] = w;
        }
        
        string ans = "";
        for(int i = 0; i < top; ++ i){
            ans += stk[i];
        }
        return ans;
    }
};
