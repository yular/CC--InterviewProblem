/*
*
* Tag: Brute Force
* Time: O(n^2)
* Space: O(1)
*/

class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size() < 2) {
            return "";
        }
        
        int l = 0, r = 0, n = s.size();
        for(int i = 0; i < n; ++ i) {
            for(int j = i + 1; j < n; ++ j) {
                if(isNiceStr(s, i, j)) {
                    if(j - i > r - l) {
                        l = i, r = j;
                    }
                }
            }
        }
        
        return l == r ? "" : s.substr(l, r - l + 1);
    }
private:
    bool isNiceStr(string &s, int l, int r) {
        vector<int> charState(26, 0);
        for(int i = l; i <= r; ++ i) {
            int idx = 0;
            if(s[i] >= 'a' && s[i] <= 'z') {
                idx = s[i] - 'a';
                charState[idx] |= 1;
                continue;
            }
            idx = s[i] - 'A';
            charState[idx] |= 2;
        }
        for(int i = 0; i < 26; ++ i) {
            if(charState[i] == 0) {
                continue;
            }
            if(charState[i] < 3) {
                return false;
            }
        }
        return true;
    }
};
