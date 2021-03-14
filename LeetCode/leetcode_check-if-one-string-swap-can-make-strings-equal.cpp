/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        if(s1 == s2) {
            return true;
        }
        
        int diffCnt = 0;
        for(int i = 0; i < s1.size(); ++ i) {
            if(s1[i] == s2[i]) {
                continue;
            }
            if(diffCnt > 0) {
                return false;
            }
            bool isFound = false;
            for(int j = i + 1; j < s2.size(); ++ j) {
                if(s1[i] == s2[j] && s2[i] == s1[j]) {
                    isFound = true;
                    ++ diffCnt;
                    swap(s2[i], s2[j]);
                    break;
                }
            }
            if(!isFound) {
                return false;
            }
        }
        return true;
    }
};
