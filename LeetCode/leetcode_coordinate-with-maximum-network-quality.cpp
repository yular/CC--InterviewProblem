/*
*
* Tag: Math
* Time: O(xyn) x is the difference between minX and maxX, y is the difference between minY and maxY
* Space: O(1)
*/

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        if(towers.size() == 0 || radius == 0) {
            return {};
        }
        
        int minX = 51, maxX = -1, minY = 51, maxY = -1;
        for(vector<int> tower : towers) {
            minX = min(minX, tower[0]), maxX = max(maxX, tower[0]);
            minY = min(minY, tower[1]), maxY = max(maxY, tower[1]);
        }
        
        vector<int> ans(2, 0);
        int r = radius*radius, maxQ = 0;
        for(int x = minX; x <= maxX; ++ x) {
            for(int y = minY; y <= maxY; ++ y) {
                int curQ = 0;
                for(vector<int> tower : towers) {
                    int dis = (x - tower[0])*(x - tower[0]) + (y - tower[1])*(y - tower[1]);
                    if(dis > r) {
                        continue;
                    }
                    
                    curQ += (int)tower[2]/(1 + sqrt(dis));
                }
                
                if(curQ > maxQ) {
                    maxQ = curQ;
                    ans[0] = x, ans[1] = y;
                }
            }
        }
        return ans;
    }
};
