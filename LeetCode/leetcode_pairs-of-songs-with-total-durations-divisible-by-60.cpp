/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    vector<int> sixties = {0, 60, 120, 180, 240, 300, 360, 420, 480, 540, 600, 660, 720, 780, 840, 900, 960, 1020};
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> numCnt;
        for(int v : time){
            ++ numCnt[v];
        }
        
        int ans = 0;
        for(int i = 0; i < time.size(); ++ i){
            -- numCnt[time[i]];
            for(int j = 0; j < sixties.size(); ++ j){
                if(sixties[j] >= time[i] && numCnt[sixties[j] - time[i]] > 0){
                    ans += numCnt[sixties[j] - time[i]];
                }
            }
        }
        return ans;
    }
};
