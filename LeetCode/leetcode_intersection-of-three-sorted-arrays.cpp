/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        if(arr1.size() == 0 || arr2.size() == 0 || arr3.size() == 0) {
            return {};
        }
        
        unordered_map<int,int> numCnt;
        for(int v : arr1) {
            ++ numCnt[v];
        }
        for(int v : arr2) {
            ++ numCnt[v];
        }
        for(int v : arr3) {
            ++ numCnt[v];
        }
        
        vector<int> ans;
        for(int v : arr1) {
            if(numCnt[v] == 3) {
                ans.push_back(v);
            }
        }
        return ans;
    }
};
