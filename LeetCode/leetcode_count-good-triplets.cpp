/*
*
* Tag: Brute Force
* Time: O(n^3)
* Space: O(1)
*/

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        if(arr.size() < 3) {
            return 0;
        }
        
        int ans = 0, n = arr.size();
        for(int i = 0; i < n; ++ i) {
            for(int j = i + 1; j < n; ++ j) {
                for(int k = j + 1; k < n; ++ k) {
                    if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c ) {
                        ++ ans;
                    }
                }
            }
        }
        return ans;
    }
};
