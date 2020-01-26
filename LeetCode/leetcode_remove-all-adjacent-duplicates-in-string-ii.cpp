/*
*
* Tag: Data Structure (Stack)
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.size() == 0){
            return "";
        }
        
        vector<char> stk(s.size(), 0);
        vector<int> charCnt(s.size(), 0);
        int top = 0;
        for(char w : s){
            if(top == 0 || stk[top - 1] != w){
                charCnt[top] = 1;
                stk[top ++] = w;
                continue;
            }
            charCnt[top] = charCnt[top - 1] + 1;
            stk[top ++] = w;
            if(charCnt[top - 1] >= k){
                top -= k;
            }
        }
        
        string ans = "";
        for(int i = 0; i < top; ++ i){
            ans += stk[i];
        }
        return ans;
    }
};
