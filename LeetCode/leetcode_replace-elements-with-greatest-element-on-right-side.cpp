/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr.size());
        if(arr.size() == 0){
            return ans;
        }
        
        int maxVal = -1;
        for(int i = arr.size() - 1; i >= 0; -- i){
            ans[i] = maxVal;
            maxVal = max(maxVal, arr[i]);
        }
        return ans;
    }
};
