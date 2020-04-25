/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int cnt = 0, id = 0;
        vector<vector<int>> board(3, vector<int>(3, -1));
        for(vector<int> move : moves) {
            board[move[0]][move[1]] = id;
            ++ cnt;
            if(canFindWinner(board, id)) {
                return id == 0? "A" : "B";
            }
            id = (id + 1)%2;
        }
        return cnt == 9? "Draw" : "Pending";
    }
private:
    bool canFindWinner(vector<vector<int>> &board, int id) {
        for(int i = 0; i < 3; ++ i) {
            if(board[i][0] == id && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                return true;
            }
            
            if(board[0][i] == id && board[0][i] == board[1][i] && board[2][i] == board[1][i]) {
                return true;
            }
        }
        
        if(board[0][0] == id && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return true;
        }
        
        if(board[0][2] == id && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return true;
        }
        return false;
    }
};
