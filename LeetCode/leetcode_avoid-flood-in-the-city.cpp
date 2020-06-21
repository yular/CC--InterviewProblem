/*
*
* Tag: Greedy +  Hash + Queue
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        if(rains.size() == 0) {
            return {};
        }
        
        int n = rains.size();
        unordered_map<int,queue<int>> lakeTimeStamp;
        for(int i = 0; i < n; ++ i) {
            if(rains[i] == 0) {
                continue;
            }
            
            lakeTimeStamp[rains[i]].push(i);
        }
        
        unordered_map<int,bool> lakeStatus;
        map<int,int> nxtRainLake;
        vector<int> ans(n, - 1);
        for(int i = 0; i < n; ++ i) {
            if(rains[i] != 0) {
                if(lakeStatus.count(rains[i]) > 0 && lakeStatus[rains[i]] == true) {
                    return {};
                }
                
                lakeStatus[rains[i]] = true;
                lakeTimeStamp[rains[i]].pop();
                if(!lakeTimeStamp[rains[i]].empty()) {
                    int time = lakeTimeStamp[rains[i]].front();
                    nxtRainLake[time] = rains[i];
                }
                continue;
            }
            
            
            if(nxtRainLake.size() == 0) {
                ans[i] = 1;
                continue;
            }
            
            auto it = nxtRainLake.begin();
            int lake = it->second;
            ans[i] = lake;
            nxtRainLake.erase(it);
            lakeStatus[lake] = false;
        }
        return ans;
    }
};
