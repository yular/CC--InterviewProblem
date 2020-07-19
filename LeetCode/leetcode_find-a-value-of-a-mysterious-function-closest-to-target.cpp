/*
*
* Tag: Bit Manipulation
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        if(arr.size() == 0) {
            return 0;
        }
        
        vector<int> uniqArr;
        uniqArr.push_back(arr[0]);
        for(int i = 1, idx = 0; i < arr.size(); i++) {
            if(arr[i] != uniqArr[idx]) {
                uniqArr.push_back(arr[i]);
                ++ idx;
            }
        }
            
        int ans = INT_MAX;
        for(int i = 0; i < uniqArr.size(); i++) {
            int v = uniqArr[i];
            ans = min(ans, abs(v - target));
            for(int j = i + 1; j < uniqArr.size(); j++) {
                v &= uniqArr[j];
                ans = min(ans, abs(v - target));
                if(v < target || ans == 0) break;
            }
        }
        return ans;
    }
};
