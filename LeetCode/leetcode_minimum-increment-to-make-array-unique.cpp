/*
*
* Status: Should Have Bug
* Tag: Greedy
* Time: O(1)
* Space: O(1)
*/
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() == 0) {
            return 0;
        }
        
        int ans = 0, maxVal = 0;
        vector<int> cnt(100100, 0);
        for(int a : A){
            ++ cnt[a];
            maxVal = max(maxVal, a);
        }
        
        for(int i = 0; i <= maxVal; ++ i){
            if(cnt[i] < 2) {
                continue;
            }
            ans += (cnt[i] - 1);
            maxVal = max(maxVal, i + 1);
            cnt[i + 1] += (cnt[i] - 1);
        }
        return ans;
    }
};
