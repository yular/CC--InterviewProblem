/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        if(items.size() == 0) {
            return 0;
        }
        
        int idx = 0;
        if(ruleKey == "color") {
            idx = 1;
        } else if(ruleKey == "name") {
            idx = 2;
        }
        
        int ans = 0;
        for(vector<string> item : items) {
            if(item[idx] == ruleValue) {
                ++ ans;
            }
        }
        return ans;
    }
};
