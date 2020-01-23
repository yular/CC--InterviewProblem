/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans;
        if(s.size() == 0){
            return ans;
        }
        
        int maxLen = 0, curLen = 0;
        for(char w : s){
            if(w == ' ') {
                maxLen = max(maxLen, curLen);
                curLen = 0;
                continue;
            }
            ++ curLen;
        }
        maxLen = max(maxLen, curLen);
        ans.resize(maxLen);
        
        int curR = 0;
        for(char w : s){
            if(w == ' '){
                while(curR != 0){
                    ans[curR] += w;
                    curR = (curR + 1)%maxLen;
                }
                continue;
            }
            
            ans[curR] += w;
            curR = (curR + 1)%maxLen;
        }
        
        for(int i = maxLen - 1; i >= 0; -- i) {
            int len = ans[i].size() - 1;
            for(; len >= 0; -- len){
                if(ans[i][len] != ' '){
                    break;
                }
            }
            if(len >= 0){
                ans[i] = ans[i].substr(0, len + 1);
            }
        }
        return ans;
    }
};
