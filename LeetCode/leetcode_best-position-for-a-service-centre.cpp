/*
*
* Tag: Geometry
* Time: ?
* Space: O(1)
*/

class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        if (positions.size() < 2) {
            return 0;
        }

        double ans = DBL_MAX;
        int n = positions.size();
        for(int i = 0; i < n; ++ i) {
            double sumDis = 0;
            for(int j = 0; j < n; ++ j) {
                sumDis += calculateDist(positions[i], positions[j]);
            }
            ans = min(ans, sumDis);
        }

        double x = -1, y = -1;
        double prev = -1, cur = calculateDistSum(positions, x, y);
        while (fabs(cur - prev) > 1e-6) {
            prev = cur;

            double sum = 0, sumX = 0, sumY = 0;
            for (vector<int> &pos : positions) {
                double v = 1 / sqrt((pos[0] - x) * (pos[0] - x) + (pos[1] - y) * (pos[1] - y));
                sum += v;
                sumX += pos[0] * v;
                sumY += pos[1] * v;
            }
            x = sumX / sum;
            y = sumY / sum;

            cur = calculateDistSum(positions, x, y);
            ans = min(ans, cur);
        }
        return ans;
    }
private:
    double calculateDist(vector<int> &a, vector<int> &b) {
        return sqrt((a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]));
    }
    
    double calculateDistSum(vector<vector<int>>& positions, double x, double y) {
        double res = 0;
        for (vector<int> &pos : positions) {
            res += sqrt((pos[0] - x) * (pos[0] - x) + (pos[1] - y) * (pos[1] - y));
        }
        return res;
    }
};
