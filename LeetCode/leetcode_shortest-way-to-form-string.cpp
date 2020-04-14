/*
*
* Tag: Hash + Greedy
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int shortestWay(string source, string target) {
        if(source == target) {
            return 1;
        }
        
        int n = source.size();
        vector<vector<int>> idxDict(n, vector<int>(26, -1));
        vector<bool> vis(26, false);
        vis[source[n - 1] - 'a'] = true;
        for(int i = n - 2; i >= 0; -- i) {
            int idx = source[i] - 'a';
            vis[idx] = true;
            idxDict[i] = idxDict[i + 1];
            idxDict[i][source[i + 1] - 'a'] = i + 1;
        }
        
        int ans = 0, idx = 0;
        for(int i = 0; i < target.size(); ++ i, idx = (idx + 1)%n) {
            int tidx = target[i] - 'a';
            if(!vis[tidx]) {
                ans = -1;
                break;
            }
            if(idx == 0) {
                ++ ans;
            }
            
            if(target[i] == source[idx]) {
                continue;
            }
            
            if(idxDict[idx][tidx] == -1) {
                ++ ans;
                idx = 0;
            }
                idx = idxDict[idx][tidx];
            }
        }
        return ans;
    }
};
