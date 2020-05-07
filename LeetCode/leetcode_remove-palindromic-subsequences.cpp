/*
*
* Tag: Two Pointer
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size() == 0) {
            return 0;
        }
        
        bool isPalind = true;
        for(int l = 0, r = s.size() - 1; l <= r; ++ l, -- r) {
            if(s[l] != s[r]) {
                isPalind = false;
                break;
            }
        }
        return isPalind ? 1 : 2;
    }
};
