/*
*
* Tag: Hash
* Time: O(nm)
* Space: O(m)
*/
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int ans = -1;
        if(mat.size() == 0){
            return ans;
        }
        
        vector<unordered_set<int>> dict(mat.size());
        for(int i = 1; i < mat.size(); ++ i){
            for(int v : mat[i]) {
                dict[i].insert(v);
            }
        }
        
        for(int v : mat[0]){
            bool canAllFound = true;
            for(int i = 1; i < dict.size(); ++ i){
                if(dict[i].count(v) == 0){
                    canAllFound = false;
                    break;
                }
            }
            if(canAllFound){
                ans = v;
                break;
            }
        }
        return ans;
    }
};
