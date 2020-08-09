/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(k == 0 && s == t) {
            return true;
        }
        if(k < s.size() || s.size() != t.size()) {
            return false;
        }
        
        vector<int> alphMoveCnt(26, 0);
        int n = s.size();
        for(int i = 0; i < n; ++ i) {
            if(s[i] == t[i]) {
                continue;
            }
            
            int diff = abs(s[i] - t[i]);
            if(s[i] > t[i]) {
                diff = 26 - diff;
            }
            if(alphMoveCnt[diff]*26 + diff > k) {
                return false;
            }
            ++ alphMoveCnt[diff];
        }
        return true;
    }
};
