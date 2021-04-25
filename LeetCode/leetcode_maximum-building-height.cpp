/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if(restrictions.size() == 0) {
            return n - 1;
        }
        
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        for (int i = 0; i < m - 1; ++i) {
            int h = restrictions[i][1] + abs(restrictions[i + 1][0] - restrictions[i][0]);
            if (h > restrictions[i + 1][1]) {
                h = restrictions[i + 1][1] + (h - restrictions[i + 1][1]) / 2;
            }
            restrictions[i + 1][1] = min(h, restrictions[i + 1][1]);
        }
        
        int res = 0;
        for (int i = m - 1; i > 0; -- i) {
            int h = restrictions[i][1] + abs(restrictions[i - 1][0] - restrictions[i][0]);
            if (h > restrictions[i - 1][1]) {
                h = restrictions[i - 1][1] + (h - restrictions[i - 1][1]) / 2;
            }
            res = max(res, h);
            restrictions[i - 1][1] = min(h, restrictions[i - 1][1]);
        }
        return res;
    }
};
