/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        if(boxes.size() == 0) {
            return 0;
        }
        
        sort(boxes.begin(), boxes.end());
        
        int ans = 0, n = boxes.size(), m = warehouse.size(), minH = warehouse[0];
        for(int i = 0; i < m; ++ i) {
            minH = min(warehouse[i], minH);
            warehouse[i] = minH;
        }
        for(int i = 0, j = m - 1; j >= 0 && i < n; -- j) {
            if(boxes[i] <= warehouse[j]) {
                ++ ans, ++ i;
            }
        }
        return ans;
    }
};
