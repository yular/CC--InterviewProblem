/*
*
* Tag: Binary Search
* Time: O(nlgm)
* Space: O(1)
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        
        int cnt = 0;
        for(vector<int> r : grid) {
            int c = getLastPositiveIdx(r);
            cnt += (r.size() - c - 1);
        }
        return cnt;
    }
    
private:
    int getLastPositiveIdx(vector<int> &arr) {
        if(arr[0] < 0) {
            return -1;
        }
        
        int l = 0, r = arr.size() - 1, ans = 0;
        while(l <= r) {
            int mid = (l + r)>>1;
            if(arr[mid] >= 0) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
