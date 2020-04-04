/*
*
* Tag: Implementation
* Time: O(max(arr[i])*n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        if(arr.size() == 0) {
            return arr;
        }
        
        int n = arr.size();
        vector<int> ans;
        for(;;) {
            vector<int> cur = arr;
            bool allEqual = true;
            for(int i = 1; i < n - 1; ++ i) {
                if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]){
                    ++ cur[i];
                } else if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                    -- cur[i];
                }
                if(cur[i] != arr[i]) {
                    allEqual = false;
                }
            }
            
            
            if(allEqual) {
                ans = arr;
                break;
            }
            arr = cur;
        }
        return ans;
    }
};
