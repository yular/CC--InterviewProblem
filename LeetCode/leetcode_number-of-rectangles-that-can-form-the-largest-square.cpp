/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        if(rectangles.size() == 0) {
            return 0;
        }
        
        int maxLen = 0, ans = 0;
        for(vector<int> r : rectangles) {
            if(maxLen < min(r[0], r[1])) {
                maxLen = max(maxLen, min(r[0], r[1]));
                ans = 1;
            } else if(maxLen == min(r[0], r[1])) {
                ++ ans;
            }
        }
        return ans;
    }
};
