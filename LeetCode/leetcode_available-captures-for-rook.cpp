/*
*
* Tag: Implementation
* Time: O(nm)
* Space: O(1)
*/
class Solution {
private:
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ans = 0;
        if(board.size() == 0) {
            return ans;
        }
        
        pair<int,int> rookPos = getRookPos(board);
        if(rookPos.first == -1) {
            return ans;
        }
        
        for(int i = 0; i < 4; ++ i){
            pair<int,int> curPos = rookPos;
            while(curPos.first >= 0 && curPos.first < 8 && curPos.second >= 0 && curPos.second < 8) {
                char val = board[curPos.first][curPos.second];
                if(val >= 'a' && val <= 'z') {
                    ++ ans;
                    break;
                }
                if(val >= 'A' && val <= 'Z' && curPos != rookPos) {
                    break;
                }
                
                curPos.first += dir[i][0];
                curPos.second += dir[i][1];
            }
        }
        return ans;
    }
private:
    pair<int,int> getRookPos(vector<vector<char>>& board) {
        for(int i = 0; i < 8; ++ i){
            for(int j = 0; j <8; ++ j){
                if(board[i][j] == 'R') {
                    return make_pair(i, j);
                }
            }
        }
        
        return make_pair(-1, -1);
    }
};
