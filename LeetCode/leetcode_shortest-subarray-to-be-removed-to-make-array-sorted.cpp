/*
*
* Tag: Two Pointers
* Time: O(n)
* Space: O(1)
* Credit from: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/discuss/830480/C%2B%2B-O(N)
*/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        if(n < 2) {
            return 0;
        }
        
        int l = 0;
        for(; l < n - 1 && arr[l] <= arr[l + 1]; ++ l) ;
        if(l == n - 1) {
            return 0;
        }
        
        int r = n - 1;
        for(; r > l && arr[r - 1] <= arr[r]; -- r) ;
        
        int ans = min(r, n - l - 1);
        for(int i = 0, j = r; i <= l && j < n;) {
            if(arr[i] <= arr[j]) {
                ans = min(ans, j - i - 1);
                ++ i;
                continue;
            }
            ++ j;
        }
        return ans;
    }
};
