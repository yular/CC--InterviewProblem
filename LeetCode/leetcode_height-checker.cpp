/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        if(heights.size() < 2) {
            return 0;
        }
        
        vector<int> sortHeights = heights;
        sort(sortHeights.begin(), sortHeights.end());
        
        int ans = 0;
        for(int i = 0; i < heights.size(); ++ i) {
            if(heights[i] != sortHeights[i]) {
                ++ ans;
            }
        }
        return ans;
    }
};
