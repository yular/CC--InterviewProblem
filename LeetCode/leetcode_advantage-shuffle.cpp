/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        if(A.size() != B.size()) {
            return {};
        }
        
        map<int,int> numCnt;
        for(int a : A) {
            ++ numCnt[a];
        }
        
        vector<int> ans(B.begin(), B.end());
        for(int i = 0; i < B.size(); ++ i) {
            auto it = numCnt.upper_bound(B[i]);
            if(it == numCnt.end()) {
                it = numCnt.begin();
            }
            ans[i] = it->first;
            -- it->second;
            if(it->second == 0) {
                numCnt.erase(it->first);
            }
        }
        return ans;
    }
};
