/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        if(heights.size() == 0) {
            return {};
        }
        
        int n = heights.size(), maxH = heights[n - 1];
        vector<int> ans = {n - 1};
        for(int i = n - 2; i >= 0; -- i) {
            if(heights[i] <= maxH) {
                continue;
            }
            ans.push_back(i);
            maxH = heights[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
