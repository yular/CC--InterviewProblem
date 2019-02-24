/*
*
* Tag: Binary Search Tree
* Time: O(mlgm + nlgm) where n is the number of total elements, and m is the number of lists
* Space: O(n)
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2);
        if(nums.size() == 0) {
            return ans;
        }
        
        map<int,queue<int>> rangeMap;
        for(int i = 0; i < nums.size(); ++ i){
            rangeMap[nums[i][0]].push(i);
        }
        
        int rangeLength = rangeMap.rbegin()->first - rangeMap.begin()->first;
        ans[0] = rangeMap.begin()->first;
        ans[1] = rangeMap.rbegin()->first;
        if(rangeLength == 0){
            return ans;
        }
        
        vector<int> idexes(nums.size(), 0);
        bool quitLoop = false;
        for(;!quitLoop;) {
            int numsIdx = rangeMap.begin()->second.front();
            rangeMap.begin()->second.pop();
                        
            if(rangeMap.begin()->second.empty()) {
                rangeMap.erase(rangeMap.begin()->first);
            }
            
            ++ idexes[numsIdx];
            if(idexes[numsIdx] >= nums[numsIdx].size()) {
                quitLoop = true;
                continue;
            }
            
            rangeMap[nums[numsIdx][idexes[numsIdx]]].push(numsIdx);
            int curRangeLength = rangeMap.rbegin()->first - rangeMap.begin()->first;
            if(curRangeLength < rangeLength) {
                rangeLength = curRangeLength;
                ans[0] = rangeMap.begin()->first;
                ans[1] = rangeMap.rbegin()->first;
            }
        }
        return ans;
    }
};
