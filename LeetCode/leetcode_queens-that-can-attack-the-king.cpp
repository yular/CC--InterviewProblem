/*
*
* Tag: Brute Force, Array
* Time: O(n)
* Space: O(n)
*/
class Solution {
private:
    int dir[8][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,0},{-1,-1},{-1,1}};
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        if(queens.size() == 0){
            return ans;
        }
        
        vector<vector<bool>> chessboard(8, vector<bool>(8, false));
        for(vector<int> queen : queens){
            chessboard[queen[0]][queen[1]] = true;
        }
        
        for(int i = 0; i < 8; ++ i) {
            int r = king[0], c = king[1];
            for(int j = 0; j < 8; ++ j) {
                r += dir[i][0], c += dir[i][1];
                if(r < 0 || r >= 8 || c < 0 || c >= 8) {
                    break;
                }
                if(chessboard[r][c]) {
                    vector<int> tmp = {r, c};
                    ans.push_back(tmp);
                    break;
                }
            }
        }
        return ans;
    }
}1
