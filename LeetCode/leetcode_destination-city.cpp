/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> outPathCnt;
        for(vector<string> path : paths) {
            ++ outPathCnt[path[0]];
            if(outPathCnt.count(path[1]) == 0) {
                outPathCnt[path[1]] = 0;
            }
        }
        
        string ans = "";
        for(pair<string,int> cnt : outPathCnt) {
            if(cnt.second == 0) {
                ans = cnt.first;
                break;
            }
        }
        return ans;
    }
};
