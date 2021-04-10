/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string truncateSentence(string s, int k) {
        if(s.size() < k) {
            return s;
        }
        
        string res = "";
        for(int i = 0, cnt = 0; i < s.size() && cnt < k; ++ i) {
            if(s[i] == ' ') {
                ++ cnt;
                if(cnt >= k) {
                    break;
                }
            }
            res += s[i];
        }
        return res;
    }
};
