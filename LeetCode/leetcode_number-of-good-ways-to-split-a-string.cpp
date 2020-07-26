/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int numSplits(string s) {
        if(s.size() == 0) {
            return 0;
        }
        
        int n = s.size();
        vector<int> cntL(n, 0), cntR(n, 0);
        vector<bool> vis(26, false);
        cntL[0] = 1;
        vis[(s[0] - 'a')] = true;
        for(int i = 1; i < n - 1; ++ i) {
            int idx = s[i] - 'a';
            cntL[i] = cntL[i - 1];
            if(!vis[idx]) {
                ++ cntL[i];
                vis[idx] = true;
            }
        }
        
        fill(vis.begin(), vis.end(), false);
        cntR[n - 1] = 1;
        vis[(s[n - 1] - 'a')] = true;
        for(int i = n - 2; i > 0; -- i) {
            int idx = s[i] - 'a';
            cntR[i] = cntR[i + 1];
            if(!vis[idx]) {
                ++ cntR[i];
                vis[idx] = true;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n - 1; ++ i) {
            if(cntL[i] == cntR[i + 1]) {
                ++ ans;
            }
        }
        return ans;
    }
};
