/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        if(word.size() < 5) {
            return 0;
        }
        
        int len = 0, ans = 0, cur = 0, uniqCnt = 0;
        for(int i = 0; i <= word.size(); ++ i) {
            if(word[i] != cur) {
                if(cur == 'a' && word[i] == 'e') {
                    ++ uniqCnt;
                } else if(cur == 'e' && word[i] == 'i') {
                    ++ uniqCnt;
                } else if(cur == 'i' && word[i] == 'o') {
                    ++ uniqCnt;
                } else if(cur == 'o' && word[i] == 'u') {
                    ++ uniqCnt;
                } else {
                    while(i + 4 < word.size()) {
                        if(word[i] == 'a') {
                            break;
                        }
                        ++ i;
                    }
                    if(i + 4 >= word.size()) {
                        break;
                    }
                    len = 0;
                    uniqCnt = 1;
                }
            }
            ++ len;
            cur = word[i];
            if(uniqCnt == 5) {
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
