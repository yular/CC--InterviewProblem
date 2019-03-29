/*
*
* Tag: Math
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int ans = 1;
        if(K == 1) {
            return ans;
        }
        
        vector<bool> vis(K, false);
        vis[1] = true;
        int modVal = 1;
        for(; ;) {
            modVal = (modVal*10 + 1)%K;
            if(vis[modVal]) {
                return -1;
            }
            ++ ans;
            if(modVal == 0) {
                break;
            }
            vis[modVal] = true;
        }
        return ans;
    }
};
