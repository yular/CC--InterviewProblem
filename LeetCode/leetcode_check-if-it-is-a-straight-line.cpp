/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
private:
    const double eps = 1e-9;
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        unordered_set<double> vis;
        
        int n = coordinates.size();
        for(int i = 0; i < n - 1; ++ i){
            double xdif = coordinates[i][0] - coordinates[i + 1][0], ydif = coordinates[i][1] - coordinates[i + 1][1];
            if(fabs(xdif - 0) <  eps) {
                vis.insert(DBL_MAX);
            } else {
                vis.insert(ydif/xdif);
            }
            if(vis.size() > 1) {
                return false;
            }
        }
        return true;
    }
};
