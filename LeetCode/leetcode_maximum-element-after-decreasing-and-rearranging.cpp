/*
*
* Tag: Greedy , Sort
* Time: O(nlgn)
* Space: O(1)
*/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if(arr.size() < 2) {
            return 1;
        }
        
        sort(arr.begin(), arr.end());
        if(arr[0] != 1) {
            arr[0] = 1;
        }
        
        int ans = 1, n = arr.size();
        for(int i = 1; i < n; ++ i) {
            if(arr[i] - arr[i - 1] > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            ans = max(ans, arr[i]);
        }
        return ans;
    }
};
