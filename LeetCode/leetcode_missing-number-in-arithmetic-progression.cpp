/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        if(arr.size() < 3) {
            return -1;
        }
        
        int n = arr.size(), diff = arr[1] - arr[0];
        if(diff != arr[n - 1] - arr[n - 2]) {
            if(abs(diff) > abs(arr[n - 1] - arr[n - 2])) {
                return arr[0] + arr[n - 1] - arr[n - 2];
            } else {
                return arr[n - 1] - diff;
            }
        }
        
        int ans = 0;
        for(int i = 1; i < n - 1; ++ i) {
            if(diff != arr[i + 1] - arr[i]){
                ans = arr[i] + diff;
                break;
            }
        }
        return ans;
    }
};
