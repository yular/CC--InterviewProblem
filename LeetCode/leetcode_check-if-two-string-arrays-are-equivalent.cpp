/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        if(word1.size() == 0 && word2.size() == 0) {
            return true;
        }
        
        int i = 0, j = 0, ci = 0, cj = 0;
        for(; i < word1.size() && j < word2.size(); ) {
            if(word1[i][ci] != word2[j][cj]) {
                return false;
            }
            ++ ci, ++ cj;
            if(ci >= word1[i].size()) {
                ++ i;
                ci = 0;
            }
            if(cj >= word2[j].size()) {
                ++ j;
                cj = 0;
            }
        }
        return i >= word1.size() && j >= word2.size();
    }
};
