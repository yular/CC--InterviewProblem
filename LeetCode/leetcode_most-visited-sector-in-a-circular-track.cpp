/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(n)
*/

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        if(n < 1 || rounds.size() == 0) {
            return {};
        }
        
        vector<int> cnt(n, 0);
        int maxCnt = 0;
        for(int i = 0; i < rounds.size() - 1; ++ i) {
            int s = rounds[i] - 1, t = rounds[i + 1] - 1;
            if(i > 0) {
                s = (s + 1)%n;
            }
            
            for(int j = s; j != t; j = (j + 1)%n) {
                ++ cnt[j];
                maxCnt = max(maxCnt, cnt[j]);
            }
            ++ cnt[t];
            maxCnt = max(maxCnt, cnt[t]);
        }
        
        vector<int> ans;
        for(int i = 0; i < n; ++ i) {
            if(cnt[i] == maxCnt) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
