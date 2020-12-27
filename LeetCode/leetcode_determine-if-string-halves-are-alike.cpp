/*
*
* Tag: implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool halvesAreAlike(string s) {
        if(s.size() == 0) {
            return true;
        }
        
        int leftCnt = 0, rightCnt = 0, n = s.size();
        for(int i = 0; i < n; ++ i) {
            if(i < n/2) {
                if(isVowel(s[i])) {
                    ++ leftCnt;
                }
            } else {
                if(isVowel(s[i])) {
                    ++ rightCnt;
                }
            }
        }
        return leftCnt == rightCnt;
    }
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
