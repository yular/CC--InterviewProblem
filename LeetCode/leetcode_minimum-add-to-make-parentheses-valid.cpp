/*
*
* Tag: Stack
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int minAddToMakeValid(string S) {
        if(S.size() == 0){
            return 0;
        }
        
        stack<char> stk;
        for(int i = 0; i < S.size(); ++ i){
            if(!stk.empty() && stk.top() == '(' && S[i] == ')') {
                stk.pop();
            } else {
                stk.push(S[i]);
            }
        }
        
        return stk.size();
    }
};
