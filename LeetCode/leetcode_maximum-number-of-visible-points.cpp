/*
*
* Tag: Geometry + Sliding Window
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& locations) {
        vector<double> angs;
        int ans = 0;
        double c = 180 / M_PI;
        for (vector<int> p : points) {
            if (p[1] == locations[1] && p[0] == locations[0]) {
                ++ ans;
                continue;
            }
            double ang = atan2(p[1] - locations[1], p[0] - locations[0]) * c;
            if(ang < 0) {
                ang = 360 + ang;
            }
            angs.push_back(ang);
        }
        
        sort(angs.begin(), angs.end());
        
        int n = angs.size(), maxCnt = 0;
        for (int l = 0, r = 0; r < n * 2; ++r) {
            while (360 * (r >= n) + angs[r % n] - 360 * (l >= n) - angs[l % n] > angle) {
                ++ l;
            }
            maxCnt = max(maxCnt, r - l + 1);
        }
        ans += maxCnt;
        
        return ans;
    }
};
