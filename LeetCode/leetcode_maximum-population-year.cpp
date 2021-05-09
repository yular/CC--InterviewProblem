/*
*
* Tag: Hash
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        if(logs.size() == 0) {
            return 0;
        }
        
        vector<int> cnt(300, 0);
        int ans = 0, maxCnt = 0;
        for(vector<int> log : logs) {
            for(int j = log[0]; j < log[1]; ++ j) {
                int idx = j - 1950;
                ++ cnt[idx];
                if(maxCnt < cnt[idx]) {
                    maxCnt = cnt[idx];
                    ans = j;
                } else if(maxCnt == cnt[idx]) {
                    ans = min(ans, j);
                }
            }
        }
        return ans;
    }
};
