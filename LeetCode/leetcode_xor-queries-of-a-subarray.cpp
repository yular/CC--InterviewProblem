/*
*
* Tag: Bit Manipulation
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0);
        if(queries.size() == 0) {
            return ans;
        }
        
        vector<int> xorArr(arr.size(), 0);
        xorArr[0] = arr[0];
        for(int i = 1; i < arr.size(); ++ i){
            xorArr[i] = (arr[i]^xorArr[i - 1]);
        }
        
        for(int i = 0; i < queries.size(); ++ i){
            ans[i] = queries[i][0] == 0? xorArr[queries[i][1]] : (xorArr[queries[i][1]]^xorArr[queries[i][0] - 1]);
        }
        return ans;
    }
};
