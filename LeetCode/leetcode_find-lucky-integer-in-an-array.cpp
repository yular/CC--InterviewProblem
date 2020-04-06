/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int findLucky(vector<int>& arr) {
        if(arr.size() == 0) {
            return -1;
        }
        
        unordered_map<int,int> numCnt;
        for(int v : arr) {
            ++ numCnt[v];
        }
        
        int ans = -1;
        for(pair<int,int> num : numCnt) {
            if(num.first == num.second) {
                ans = max(ans, num.first);
            }
        }
        return ans;
    }
};
