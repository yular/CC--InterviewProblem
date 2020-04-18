/*
*
* Tag: Hash + Implementation
* Time: O(n)
* Space: O(m)
*/

class Solution {
private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, unordered_set<int>> dict;
        for(vector<int> obs : obstacles) {
            dict[obs[0]].insert(obs[1]);
        }
        
        pair<int,int> loc = make_pair(0, 0);
        int d = 0, ans = 0;
        for(int cmd : commands) {
            switch(cmd) {
                case -1:
                    d = (d + 1)%4;
                    break;
                case -2:
                    d = (d + 3)%4;
                    break;
                default:
                    for(int i = 0; i < cmd; ++ i) {
                        int nxt_r = loc.first + dir[d][0], nxt_c = loc.second + dir[d][1];
                        if(dict.count(nxt_r) > 0 && dict[nxt_r].count(nxt_c) > 0) {
                            break;
                        }
                        loc.first = nxt_r, loc.second = nxt_c;
                        ans = max(ans, loc.first*loc.first + loc.second*loc.second);
                    }
            }
        }
        return ans;
    }
};
