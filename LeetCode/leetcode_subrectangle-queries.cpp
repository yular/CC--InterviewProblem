/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(1)
*/

class SubrectangleQueries {
private:
    vector<vector<int>> mtx;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        mtx = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; ++ i) {
            for(int j = col1; j <= col2; ++ j) {
                mtx[i][j] = newValue;
            }
        }
        
        return;
    }
    
    int getValue(int row, int col) {
        return mtx[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
