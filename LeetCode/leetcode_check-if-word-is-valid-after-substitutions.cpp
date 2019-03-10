/*
*
* Tag: Stack
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool isValid(string S) {
        if(S == ""){
            return true;
        }
        
        vector<char> stk(S.size());
        int top = 0;
        for(char s : S){
            if(s != 'c') {
                stk[top ++] = s;
            } else if(top >= 2){
                if(stk[top - 1] == 'b' && stk[top - 2] == 'a') {
                    top -= 2;
                } else {
                    return false;
                }
            }
        }
        
        return top == 0;
    }
};
