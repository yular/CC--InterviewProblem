/*
*
* Tag: Sort + Hash
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size() == 0) {
            return {};
        }
        
        map<int,int> numCnt;
        for(int v : arr1) {
            ++ numCnt[v];
        }
        
        vector<int> ans(arr1.size(), 0);
        int idx = 0;
        for(int i = 0; i < arr2.size(); ++ i) {
            for(int j = 0; j < numCnt[arr2[i]]; ++ j) {
                ans[idx ++] = arr2[i];
            }
            numCnt.erase(arr2[i]);
        }
        
        for(auto it = numCnt.begin(); it != numCnt.end(); ++ it) {
            for(int j = 0; j < it->second; ++ j) {
                ans[idx ++] = it->first;
            }
        }
        return ans;
    }
};
