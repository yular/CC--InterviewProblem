/*
*
* Tag: Binary Search
* Time: O(nlgm)
* Space: O(1)
*/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        
        int n = dim[0], m = dim[1];
        int ans = n + 1;
        for(int i = 0; i < n; ++ i) {
            int curAns = -1, l = 0, r = m - 1;
            while(l <= r) {
                int mid = (l + r)>>1;
                int v = binaryMatrix.get(i, mid);
                if(v == 1) {
                    curAns = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            
            if(curAns != -1) {
                ans = min(ans, curAns);
            }
        }
        
        return ans == n + 1? -1 : ans;
    }
};
