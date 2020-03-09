/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minSteps(string s, string t) {
        if(s == t) {
            return 0;
        }
        if(s.size() != t.size()) {
            return -1;
        }
        
        vector<int> charCntS(26, 0), charCntT(26, 0);
        for(char c : s) {
            ++ charCntS[c - 'a'];
        }
        for(char c : t) {
            ++ charCntT[c - 'a'];
        }
        
        int ans = 0;
        for(int i = 0; i < 26; ++ i) {
            if(charCntS[i] >= charCntT[i]) {
                continue;
            }
            ans += (charCntT[i] - charCntS[i]);
        }
        return ans;
    }
};
