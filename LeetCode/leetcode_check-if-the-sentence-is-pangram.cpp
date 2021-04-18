/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size() < 26) {
            return false;
        }
        
        vector<bool> dic(26, false);
        int cnt = 0;
        for(char c : sentence) {
            int idx = c - 'a';
            if(dic[idx]) {
                continue;
            }
            ++ cnt;
            dic[idx] = true;
        }
        return cnt >= 26;
    }
};
