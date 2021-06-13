/*
*
* Tag: Math / Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size() == 0) {
            return true;
        }
        
        vector<int> charCnt(26, 0);
        for(string w : words) {
            for(char c : w) {
                int idx = c - 'a';
                ++ charCnt[idx];
            }
        }
        int n = words.size();
        for(int i = 0; i < 26; ++ i) {
            if(charCnt[i]%n != 0) {
                return false;
            }
        }
        return true;
    }
};
