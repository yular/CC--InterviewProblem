/*
*
* Tag: Binary Search
* Time: O(nmlg(min(n, m))
* Space: O(1)
*/

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        if(mat.size() == 0) {
            return 0;
        }
        
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                if(j > 0) {
                    mat[i][j] += mat[i][j - 1];
                }
            }
            if(i == 0) {
                continue;
            }
            
            for(int j = 0; j < m; ++ j) {
                mat[i][j] += mat[i - 1][j];
            }
        }
        
        int ans = 0, l = 1, r = min(n, m);
        while(l <= r) {
            int mid = (l + r)>>1;
            if(canFindSquare(mat, mid, threshold)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return ans;
    }
private:
    bool canFindSquare(vector<vector<int>> &mat, int l, int v) {
        int n = mat.size(), m = mat[0].size();
        for(int i = l - 1; i < n; ++ i) {
            for(int j = l - 1; j < m; ++ j) {
                int sum = mat[i][j];
                if(i - l >= 0) {
                    sum -= mat[i - l][j];
                }
                if(j - l >= 0) {
                    sum -= mat[i][j - l];
                }
                if(i - l >= 0 && j - l >= 0) {
                    sum += mat[i - l][j - l];
                }
                if(sum <= v) {
                    return true;
                }
            }
        }
        return false;
    }
};
