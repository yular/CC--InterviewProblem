/*
*
* Tag: Divide and Conquer
* Time: O(lgn)
* Space: O(lgn)
*/
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
private:
    unordered_map<int,unordered_set<int>> vis;
    int dir[4][2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        if(topRight[0] < bottomLeft[0] || topRight[1] < bottomLeft[1]) {
            return 0;
        }
        
        if(!sea.hasShips(topRight, bottomLeft)) {
            return 0;
        }
        
        int width = topRight[0] - bottomLeft[0], height = topRight[1] - bottomLeft[1];
        if(width == 1 && height == 1) {
            int ans = 0;
            for(int i = 0; i < 4; ++ i){
                int x = bottomLeft[0] + dir[i][0], y = bottomLeft[1] + dir[i][1];
                if(sea.hasShips({x, y}, {x, y})){
                    ++ ans;
                }
            }
            return ans;
        }
        if(width == 0 && height == 0) {
            return 1;
        }
        
        return countShips(sea, {bottomLeft[0] + width/2, bottomLeft[1] + height/2}, bottomLeft) + countShips(sea, topRight, {bottomLeft[0] + width/2 + 1, bottomLeft[1] + height/2 + 1}) + countShips(sea, {bottomLeft[0] + width/2, topRight[1]}, {bottomLeft[0], bottomLeft[1] + height/2 + 1}) + countShips(sea, {topRight[0], bottomLeft[1] + height/2}, {bottomLeft[0] + width/2 + 1, bottomLeft[1]});
    }
};
