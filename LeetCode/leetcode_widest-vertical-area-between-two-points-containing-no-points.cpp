/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        if(points.size() < 2) {
            return 0;
        }
        
        sort(points.begin(), points.end(), cmp);
        
        int ans = 0, n = points.size();
        for(int i = 1; i < n; ++ i) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        return ans;
    }
private:
    struct comparator {
        bool operator() (vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        }
    }cmp;
};
