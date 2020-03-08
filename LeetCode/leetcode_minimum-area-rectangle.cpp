/*
*
* Tag: Hash
* Time: O(n^2lgn)
* Space: O(n^2)
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        if(points.size() == 0){
            return 0;
        }
        
        unordered_map<int,unordered_set<int>> xAsis, yAsis;
        for(vector<int> point : points) {
            xAsis[point[0]].insert(point[1]);
            yAsis[point[1]].insert(point[0]);
        }
        
        int ans = INT_MAX;
        for(auto i = xAsis.begin(); i != xAsis.end(); ++ i) {
            auto j = i;
            for(++ j; j != xAsis.end(); ++ j){
                set<int> commony;
                for(int y : i->second) {
                    if(j->second.count(y) > 0) {
                        commony.insert(y);
                    }
                }
                
                if(commony.size() < 2) {
                    continue;
                }
                
                for(auto y = commony.begin(); y != commony.end(); y ++) {
                    auto nxt_y = y;
                    ++ nxt_y;
                    if(nxt_y == commony.end()) {
                        continue;
                    }
                    int area = abs(i->first - j->first) * (*nxt_y - *y);
                    ans = min(ans, area);
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
