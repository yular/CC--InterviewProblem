/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    bool validPalindrome(string s) {
        if(s.size() < 2) {
            return true;
        }
        
        bool hasDeleted = false, success = true;
        for(int i = 0, j = s.size() - 1; i < j; ++i, --j){
            if(s[i] != s[j]) {
                if(hasDeleted) {
                    success = false;
                    break;
                }
                if(s[i + 1] == s[j]) {
                    ++ i;
                } else {
                    success = false;
                    break;
                }
                hasDeleted = true;
            }
        }
        if(success) {
            return true;
        }
        
        hasDeleted = false, success = true;
        for(int i = 0, j = s.size() - 1; i < j; ++i, --j){
            if(s[i] != s[j]) {
                if(hasDeleted) {
                    success = false;
                    break;
                }
                if(s[i] == s[j - 1]) {
                    -- j;
                } else {
                    success = false;
                    break;
                }
                hasDeleted = true;
            }
        }
        return success;
    }
};
