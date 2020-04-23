/*
*
* Tag: Brute Force
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if(arr.size() < 2) {
            return arr[0];
        }
        
        int n = arr.size(), cur = arr[0], cnt = 1, ans = 0;
        for(int i = 1; i < n; ++ i) {
            if(cur == arr[i]) {
                ++ cnt;
            } else {
                cur = arr[i];
                cnt = 1;
            }
            if(cnt*4 > n) {
                ans = cur;
                break;
            }
        }
        
        return ans;
    }
};
