/*
*
* Tag: HashMap
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int ans = -1;
        if(A.size() == 0) {
            return ans;
        }
        
        unordered_map<int,int> numCnt;
        for(int a : A){
            ++ numCnt[a];
        }
        
        for(auto i = numCnt.begin(); i != numCnt.end(); i ++){
            if(i->second == 1) {
                ans = max(ans, i->first);
            }
        }
        return ans;
    }
};
