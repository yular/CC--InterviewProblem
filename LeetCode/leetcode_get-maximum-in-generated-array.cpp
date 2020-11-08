/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n < 2) {
            return n;
        }
        
        vector<int> arr(n + 1, 0);
        arr[1] = 1;
        int ans = 1;
        for(int i = 1; 2*i <= n; ++ i) {
            int idx = 2*i;
            arr[idx] = arr[i];
            ans = max(arr[idx], ans);
            if(idx + 1 <= n) {
                arr[idx + 1] = arr[i] + arr[i + 1];
                ans = max(arr[idx + 1], ans);
            }
        }
        return ans;
    }
};
