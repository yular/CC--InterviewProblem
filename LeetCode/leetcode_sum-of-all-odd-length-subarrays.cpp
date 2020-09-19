/*
*
* Tag: Brute Force
* Time: O(n^2)
* Space: O(1)
*/

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        if(arr.size() == 0){
            return 0;
        }
        
        int ans = 0, n = arr.size();
        for(int len = 1; len <= n; len += 2) {
            int sum = 0;
            for(int i = 0; i < n; ++ i){
                sum += arr[i];
                if(i >= len) {
                    sum -= arr[i - len];
                }
                if(i >= len - 1) {
                    ans += sum;
                }
            }
        }
        return ans;
    }
};
