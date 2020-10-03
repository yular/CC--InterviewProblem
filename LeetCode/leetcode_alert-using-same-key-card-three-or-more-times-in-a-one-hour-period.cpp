/*
*
* Tag: Hash + Implementation
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        if(keyName.size() != keyTime.size()) {
            return {};
        }
        
        int n = keyName.size();
        unordered_map<string,vector<int>> visHistory;
        for(int i = 0; i < n; ++ i) {
            int h = stoi(keyTime[i].substr(0,2)), m = stoi(keyTime[i].substr(3,2));
            int totTime = h*60 + m;
            visHistory[keyName[i]].push_back(totTime);
        }
        
        for(auto i = visHistory.begin(); i != visHistory.end(); i ++) {
            sort(i->second.begin(), i->second.end());
        }
        
        vector<string> ans;
        for(auto it = visHistory.begin(); it != visHistory.end(); it ++) {
            vector<int> history = it->second;
            bool canAlert = false;
            for(int i = 0; i < history.size() - 2; ++ i) {
                if(history[i + 1] - history[i] <= 60 && history[i + 2] - history[i] <= 60) {
                    canAlert = true;
                    break;
                }
            }
             
             if(canAlert) {
                 ans.push_back(it->first);
             }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
