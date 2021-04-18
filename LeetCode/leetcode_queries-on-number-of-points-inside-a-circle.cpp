/*
*
* Tag: Math
* Time: O(nm)
* Space: O(1)
*/

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        if(queries.size() == 0) {
            return {};
        }
        
        int n = points.size(), m = queries.size();
        vector<int> ans(m, 0);
        for(int i = 0; i < m; ++ i) {
            int r = queries[i][2]*queries[i][2];
            for(int j = 0; j < n; ++ j) {
                int dis = (queries[i][0] - points[j][0])*(queries[i][0] - points[j][0]) + (queries[i][1] - points[j][1])*(queries[i][1] - points[j][1]);
                if(dis <= r) {
                    ++ ans[i];
                }
            }
        }
        return ans;
    }
};
