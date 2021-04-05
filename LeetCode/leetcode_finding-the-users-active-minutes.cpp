/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        if(logs.size() == 0) {
            return {};
        }
        
        unordered_map<int,unordered_set<int>> uam;
        for(vector<int> log : logs) {
            uam[log[0]].insert(log[1]);
        }
        
        vector<int> ans(k, 0);
        for(auto it : uam) {
            int cnt = it.second.size();
            ++ ans[cnt - 1];
        }
        return ans;
    }
};
