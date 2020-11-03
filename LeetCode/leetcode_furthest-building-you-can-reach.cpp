/*
*
* Tag: Greedy
* Time: O(nlgm)
* Space: O(n)
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if(heights.size() == 0) {
            return 0;
        }
        
        int ans = 0, n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n - 1; ++ i) {
            int d = heights[i + 1] - heights[i];
            if(d > 0) {
                pq.push(d);
            }
            if(pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }
            if(bricks < 0) {
                return i;
            }
        }
        return n - 1;
    }
};
