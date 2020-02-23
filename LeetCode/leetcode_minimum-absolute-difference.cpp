/*
*
* Tag: Implementation
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        if(arr.size() == 0){
            return ans;
        }
        
        sort(arr.begin(), arr.end());
        
        int mindiff = INT_MAX;
        for(int i = 0; i < arr.size() - 1; ++ i){
            mindiff = min(mindiff, arr[i + 1] - arr[i]);
        }
        
        for(int i = 0; i < arr.size() - 1; ++ i) {
            if(arr[i + 1] - arr[i] == mindiff) {
                vector<int> vec = {arr[i], arr[i + 1]};
                ans.push_back(vec);
            }
        }
        
        return ans;
    }
};
