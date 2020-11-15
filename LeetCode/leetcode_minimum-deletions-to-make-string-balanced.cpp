/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minimumDeletions(string s) {
        if(s.size() < 2) {
            return 0;
        }
        
        int l = 0, r = s.size() - 1;
        for(; l < s.size(); ++ l) {
            if(s[l] == 'b') {
                break;
            }
        }
        for(; r >= 0; -- r) {
            if(s[r] == 'a') {
                break;
            }
        }
        if(r < l) {
            return 0;
        }
        
        int numa = 0, numb = 0;
        for(int i = l; i <= r; ++ i) {
            if(s[i] == 'b') {
                ++ numb;
            } else {
                ++ numa;
            }
        }
        
        int ans = 0;
        for(; l <= r; ) {
            if(numb <= numa) {
                ++ l;
                -- numb;
                while(l <= r && s[l] =='a') {
                    ++ l;
                    -- numa;
                }
            } else {
                -- r;
                -- numa;
                while(l <= r && s[r] =='b') {
                    -- r;
                    -- numb;
                }
            }
            ++ ans;
        }
        return ans;
    }
};
