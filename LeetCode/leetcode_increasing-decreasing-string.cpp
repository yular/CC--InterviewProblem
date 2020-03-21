/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string sortString(string s) {
        if(s.size() == 0) {
            return s;
        }
        
        vector<int> charCnt(26, 0);
        for(char c : s) {
            ++ charCnt[(int)(c - 'a')];
        }
        
        string ans = "";
        for(int i = 0; i < s.size();) {
            for(int j = 0; j < 26; ++ j) {
                if(charCnt[j] == 0) {
                    continue;
                }
                ans += ('a' + j);
                -- charCnt[j];
                ++ i;
            }
            for(int j = 25; j >= 0; -- j) {
                if(charCnt[j] == 0) {
                    continue;
                }
                ans += ('a' + j);
                -- charCnt[j];
                ++ i;
            }
        }
        return ans;
    }
};
