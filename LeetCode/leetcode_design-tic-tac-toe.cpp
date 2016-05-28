/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n^2)
*/
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n);
        for(int i = 0; i < n; ++ i){
            vector<int> vec(n);
            board[i] = vec;
            for(int j = 0; j < n; ++ j)
                board[i][j] = 0;
        }
        bnd = n;
    }
    

    int move(int row, int col, int player) {
        int res = 0;
        board[row][col] = player;
        for(int i = 0; i < 8; i += 2){
            int cnt = 1;
            int nx = row, ny = col;
            while(1){
                nx = nx + dir[i][0], ny = ny + dir[i][1];
                if(nx >= 0 && nx < bnd && ny >= 0 && ny < bnd && board[nx][ny] == player)
                    ++ cnt;
                else
                    break;
            }
            nx = row, ny = col;
            while(1){
                nx = nx + dir[i + 1][0], ny = ny + dir[i + 1][1];
                if(nx >= 0 && nx < bnd && ny >= 0 && ny < bnd && board[nx][ny] == player)
                    ++ cnt;
                else
                    break;
            }
            if(cnt >= bnd){
                res = player;
                break;
            }
        }
        return res;
    }
private:
vector<vector<int>> board;
int bnd;
int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
};

/*
*
* Tag: Implementation
* Time: O(1)
* Space: O(n)
*/
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n);
        cols.resize(n);
        diag = antidiag = 0;
        bnd = n;
    }
    
    int move(int row, int col, int player) {
        int res = 0;
        int add = player == 1?1:-1;
        rows[row] += add;
        cols[col] += add;
        diag += row == col?add:0;
        antidiag += row == bnd - 1 - col?add:0;
        if(abs(rows[row]) == bnd || abs(cols[col]) == bnd || abs(diag) == bnd || abs(antidiag) == bnd )
            res = player == 1?1:2;
        return res;
    }
private:
vector<int> rows, cols;
int bnd, diag, antidiag;
};

