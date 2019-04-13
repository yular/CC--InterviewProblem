/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans = "";
        if(S.size() == 0) {
            return ans;
        }
        
        int inStkCnt = 0;
        for(int i = 0; i < S.size(); ++ i){
            bool canDelete = false;
            if(S[i] == '(') {
                if(inStkCnt == 0) {
                    canDelete = true;
                }
                ++ inStkCnt;
            } else {
                -- inStkCnt;
                if(inStkCnt == 0) {
                    canDelete = true;
                }
            }
            if(!canDelete) {
                ans += S[i];
            }
        }
        
        return ans;
    }
};
