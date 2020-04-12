/*
*
* Tag: Brute Force
* Time: O((nm)^2)
* Space: O(1)
*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        if(words.size() == 0) {
            return {};
        }
        
        vector<string> ans;
        for(int i = 0; i < words.size(); ++ i) {
            for(int j = 0; j < words.size(); ++ j) {
                if(i == j || words[i].size() > words[j].size()) {
                    continue;
                }
                
                int idx = words[j].find(words[i]);
                if(idx == -1) {
                    continue;
                }
                ans.push_back(words[i]);
                break;
            }
        }
        return ans;
    }
};
