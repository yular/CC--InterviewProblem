/*
*
* Tag: Greedy
* Time: O(n^2)
* Space: O(1)
*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid.size() != grid[0].size()) {
            return 0;
        }
        
        int ans = 0, n = grid.size();
        for(int i = 0, zeroCnt = n - 1; i < n - 1; ++ i, -- zeroCnt) {
            bool isFound = false;
            int j = i;
            for(; j < n; ++ j) {
                int cnt = 0;
                for(int k = i + 1; k < n; ++ k) {
                    cnt += (grid[j][k] == 0? 1 : 0);
                }
                
                if(cnt >= zeroCnt) {
                    isFound = true;
                    break;
                }
            }
            
            if(!isFound) {
                ans = -1;
                break;
            }
            if(j == i) {
                continue;
            }
            
            for(int k = j - 1; k >= i; -- k) {
                swap(grid[k], grid[k + 1]);
                ++ ans;
            }
        }
        return ans;
    }
};
