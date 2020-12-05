/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        if(seq.size() == 0) {
            return {};
        }
        
        int n = seq.size(), curSet = 1;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; ++ i) {
            if(seq[i] == '(') {
                curSet ^= 1;
                ans[i] = curSet;
            } else {
                ans[i] = curSet;
                curSet ^= 1;
            }
        }
        return ans;
    }
};
