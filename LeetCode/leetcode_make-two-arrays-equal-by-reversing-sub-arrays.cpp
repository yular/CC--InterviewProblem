/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size() != arr.size()) {
            return false;
        }
        
        unordered_map<int,int> numCnt;
        for(int v : arr) {
            ++ numCnt[v];
        }
        
        for(int i = 0; i < arr.size(); ++ i) {
            if(numCnt.count(target[i]) == 0 || numCnt[target[i]] == 0) {
                    return false;
            }
            -- numCnt[target[i]];
        }
        return true;
    }
};
