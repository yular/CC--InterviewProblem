/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1 == word2) {
            return true;
        }
        if(word1.size() != word2.size()) {
            return false;
        }
        
        vector<int> charCnt1(26, 0), charCnt2(26, 0);
        for(char c : word1){
            ++ charCnt1[c - 'a'];
        }
        for(char c : word2) {
            ++ charCnt2[c - 'a'];
        }
        
        for(int i = 0; i < 26; ++ i) {
            if( (charCnt1[i] > 0 && charCnt2[i] == 0) || (charCnt1[i] == 0 && charCnt2[i] > 0) ) {
                return false;
            }
            if(charCnt1[i] == 0 && charCnt2[i] == 0) {
                continue;
            }
            
            for(int j = i + 1; j < 26; ++ j) {
                if(charCnt1[j] == charCnt2[i]) {
                    swap(charCnt1[j], charCnt1[i]);
                    break;
                }
            }
            if(charCnt1[i] != charCnt2[i]) {
                return false;
            }
        }
        return true;
    }
};
