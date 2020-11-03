/*
*
* Tag: Implementation
* Time: O(nN)
* Space: O(m)
*/

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        if(arr.size() == 0 || pieces.size() == 0) {
            return false;
        }
        
        int n = arr.size(), m = pieces.size();
        vector<bool> vis(m, false);
        for(int i = 0; i < n;) {
            bool hasMatch = false;
            for(int j = 0; j < m; ++ j) {
                if(vis[j] || i + pieces[j].size() > n) {
                    continue;
                }
                
                bool isMatched = true;
                for(int k = 0; k < pieces[j].size() && i < n; ++ i, ++ k) {
                    if(pieces[j][k] != arr[i]) {
                        isMatched = false;
                        break;
                    }
                }
                vis[j] = isMatched;
                if(isMatched) {
                    hasMatch = true;
                }
            }
            if(!hasMatch) {
                return false;
            }
        }
        return true;
    }
};
