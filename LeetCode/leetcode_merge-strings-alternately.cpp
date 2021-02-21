/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if(word1.size() == 0) {
            return word2;
        }
        if(word2.size() == 0) {
            return word1;
        }
        
        string ans = word1 + word2;
        int n = word1.size(), m = word2.size(), i = 0, j = 0, k = 0;
        for(; i < n && j < m; ++ i, ++ j) {
            ans[k ++] = word1[i];
            ans[k ++] = word2[j];
        }
        for(; i < n; ++ i) {
            ans[k ++] = word1[i];
        }
        for(; j < m; ++ j) {
            ans[k ++] = word2[j];
        }
        return ans;
    }
};
