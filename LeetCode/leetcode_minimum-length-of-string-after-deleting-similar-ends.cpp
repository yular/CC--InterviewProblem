/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minimumLength(string s) {
        if(s.size() < 2) {
            return (int)s.size();
        }
        
        int len = s.size(), cnt = 0, n = s.size();
        for(int l = 0, r = n - 1; l < r; ) {
            if(s[l] != s[r]) {
                break;
            }
            
            char v = s[l];
            while(l <= r && s[l] == v) {
                ++ cnt;
                ++ l;
            }
            while(l <= r && s[r] == v) {
                ++ cnt;
                -- r;
            }
        }
        return cnt >= len ? 0 : len - cnt;
    }
};
