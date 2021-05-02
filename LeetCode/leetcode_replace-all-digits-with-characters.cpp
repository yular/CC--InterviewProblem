/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string replaceDigits(string s) {
        if(s.size() < 2) {
            return s;
        }
        
        int n = s.size();
        for(int i = 1; i < n; i += 2) {
            int x = s[i] - '0';
            char c = s[i - 1] + x;
            s[i] = c;
        }
        return s;
    }
};
