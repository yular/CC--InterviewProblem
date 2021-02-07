/*
*
* Tag: Greedy
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    string largestMerge(string word1, string word2) {
        if(word1.size() == 0) {
            return word2;
        }
        if(word2.size() == 0) {
            return word1;
        }
        
        string ans = "";
        int i = 0, j = 0, n = word1.size(), m = word2.size();
        for(; i < n && j < m;) {
            if(word1[i] > word2[j]) {
                ans += word1[i ++];
            } else if(word2[j] > word1[i]) {
                ans += word2[j ++];
            } else {
                if(word1.substr(i) >=  word2.substr(j)) {
                    ans += word1[i ++];
                } else {
                    ans += word2[j ++];
                }
            }
        }
        if(i < n) {
            ans += word1.substr(i);
        }
        if(j < m) {
            ans += word2.substr(j);
        }
        return ans;
    }
};
