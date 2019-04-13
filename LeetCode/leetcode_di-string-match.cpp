/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        if(S.size() == 0){
            return ans;
        }
        
        int n = S.size();
        int low = 0, high = n;
        ans.resize(n + 1);
        for(int i = 0; i < n; ++ i){
            if(S[i] == 'I') {
                ans[i] = low ++ ;
            } else {
                ans[i] = high --;
            }
        }
        ans[n] = low;
        return ans;
    }
};
