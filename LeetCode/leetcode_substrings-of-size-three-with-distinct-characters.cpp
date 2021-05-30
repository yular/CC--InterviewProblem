/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3) {
            return 0;
        }
        
        int ans = 0, n = s.size();
        vector<int> charCnt(26, 0);
        for(int i = 0; i < n; ++ i) {
            int idx = s[i] - 'a';
            ++ charCnt[idx];
            if(i < 2) {
                continue;
            }
            if(isGoodStr(charCnt)) {
                ++ ans;
            }
            idx = s[i - 2] - 'a';
            -- charCnt[idx];
        }
        return ans;
    }
private:
    bool isGoodStr(vector<int> &charCnt) {
        for(int i = 0; i < 26; ++ i) {
            if(charCnt[i] > 1) {
                return false;
            }
        }
        return true;
    }
};
