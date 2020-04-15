/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        if(fronts.size() != backs.size() || fronts.size() == 0) {
            return 0;
        }
        
        int n = fronts.size();
        unordered_set<int> invalidNums;
        for(int i = 0; i < n; ++ i) {
            if(fronts[i] == backs[i]) {
                invalidNums.insert(fronts[i]);
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < n; ++ i) {
            if(invalidNums.count(fronts[i]) == 0) {
                ans = min(ans, fronts[i]);
            }
            if(invalidNums.count(backs[i]) == 0) {
                ans = min(ans, backs[i]);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
