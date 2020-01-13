/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        if(groupSizes.size() == 0) {
            return ans;
        }
        
        unordered_map<int,vector<int>> groups;
        for(int i = 0; i < groupSizes.size(); ++ i){
            groups[groupSizes[i]].push_back(i);
        }
        for(pair<int, vector<int>> group : groups){
            int i = 0, groupSize = group.first;
            for(; i < group.second.size(); i += groupSize){
                vector<int> curGroup(groupSize, 0);
                for(int j = 0; j < groupSize; ++ j){
                    curGroup[j] = group.second[i + j];
                }
                ans.push_back(curGroup);
            }
        }
        return ans;
    }
};
