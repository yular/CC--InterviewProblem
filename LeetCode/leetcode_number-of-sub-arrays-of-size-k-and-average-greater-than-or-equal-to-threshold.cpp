/*
*
* Tag: Two Pointers, Sliding Window
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;
        long long sum = 0, lowerBound = ((long long)k) * threshold;
        for(int l = 0, r = 0; r < arr.size(); ++ r){
            sum += arr[r];
            if(r < k - 1){
                continue;
            }
            
            if(sum >= lowerBound) {
                ++ ans;
            }
            sum -= arr[l];
            ++ l;
        }
        
        return ans;
    }
};
