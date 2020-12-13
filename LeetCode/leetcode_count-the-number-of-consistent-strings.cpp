/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        if(allowed.size() == 0) {
            return 0;
        }
        
        vector<bool> dict(26, false);
        for(char c : allowed) {
            dict[c - 'a'] = true;
        }
        
        int ans = 0;
        for(string w : words) {
            bool isConsist = true;
            for(char c : w) {
                int idx = c - 'a';
                if(!dict[idx]) {
                    isConsist = false;
                    break;
                }
            }
            if(isConsist) {
                ++ ans;
            }
        }
        return ans;
    }
};
