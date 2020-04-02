/*
*
* Tag: Stack
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> charCnt(26, 0);
        for(char ch : text){
            ++ charCnt[(int)(ch - 'a')];
        }
        
        vector<char> stk(text.size(), 0);
        vector<bool> inStk(26, false);
        int top = 0;
        for(int i = 0; i < text.size(); ++ i) {
            int idx = text[i] - 'a';
            if(inStk[idx]) {
                -- charCnt[idx];
                continue;
            }
            
            while(top > 0) {
                int curIdx = (int)(stk[top - 1] - 'a');
                if(stk[top - 1] < text[i] || charCnt[curIdx] == 0) {
                    break;
                }
                
                -- top;
                inStk[curIdx] = false;
            }
            stk[top ++ ] = text[i];
            inStk[idx] = true;
            -- charCnt[idx];
        }
        
        string ans = "";
        for(int i = 0; i < top; ++ i) {
            ans += stk[i];
        }
        return ans;
    }
};
