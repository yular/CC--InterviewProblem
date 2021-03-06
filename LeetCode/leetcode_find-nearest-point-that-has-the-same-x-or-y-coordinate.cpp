/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        if(points.size() == 0) {
            return 0;
        }
        
        int ans = -1, dis = INT_MAX, n = points.size();
        for(int i = 0; i < n; ++ i) {
            vector<int> point = points[i];
            if(point[0] != x && point[1] != y) {
                continue;
            }
            int cur = abs(point[0] - x) + abs(point[1] - y);
            if(cur < dis) {
                dis = cur;
                ans = i;
            }
        }
        return ans;
    }
};
