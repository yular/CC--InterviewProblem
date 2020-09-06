/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string modifyString(string s) {
        if(s.size() == 0) {
            return s;
        }
        
        for(int i = 0; i < s.size(); ++ i) {
            if(s[i] != '?') {
                continue;
            }
            
            for(char c = 'a'; c <= 'z'; ++ c) {
                if( (i > 0 && c == s[i - 1]) || (i < s.size() - 1 && c == s[i + 1]) ) {
                    continue;
                }
                
                s[i] = c;
                break;
            }
        }
        return s;
    }
};leetcode_replace-all-s-to-avoid-consecutive-repeating-characters.cpp
