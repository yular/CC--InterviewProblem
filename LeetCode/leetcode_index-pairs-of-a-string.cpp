/*
*
* Tag: Implementation
* Time: O(n^2*lgn)
* Space: O(n)
*/

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        if(text.size() == 0 || words.size() == 0) {
            return ans;
        }
        
        unordered_map<int,unordered_set<int>> vis;
        for(string word : words) {
            for(int i = 0; i < text.size(); ++ i) {
                int idx = text.find(word, i);
                if(idx < 0) {
                    break;
                }
                
                int endIdx = idx + (int)word.size() - 1;
                if(vis[idx].count(endIdx) > 0) {
                    continue;
                }
                vis[idx].insert(endIdx);
                ans.push_back({idx, endIdx});
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
