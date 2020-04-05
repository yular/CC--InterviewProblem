/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size()) {
            return false;
        }
        
        unordered_map<char,int> charCnt;
        int oddCnt = 0;
        for(char c : s) {
            ++ charCnt[c];
            if(charCnt[c]%2 == 0) {
                -- oddCnt;
            } else {
                ++ oddCnt;
            }
        }
        
        return oddCnt <= k;
    }
};
