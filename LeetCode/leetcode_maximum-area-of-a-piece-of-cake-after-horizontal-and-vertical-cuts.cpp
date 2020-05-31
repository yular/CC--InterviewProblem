/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
private:
    const int MOD = 1e9+7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        if(horizontalCuts.size() == 0 || verticalCuts.size() == 0) {
            return 0;
        }
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int n = horizontalCuts.size(), m = verticalCuts.size();
        long long maxH = max(horizontalCuts[0], h - horizontalCuts[n - 1]), maxW = max(verticalCuts[0], w - verticalCuts[m - 1]);
        
        for(int i = 1; i < n; ++ i) {
            maxH = max(maxH, (long long)horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for(int i = 1; i < m; ++ i) {
            maxW = max(maxW, (long long)verticalCuts[i] - verticalCuts[i - 1]);
        }
        
        return (maxH*maxW)%MOD;
    }
};
