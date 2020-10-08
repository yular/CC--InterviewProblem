/*
*
* Tag: Greedy
* Time: O(nm)
* Space: O(nm)
*/
// output limit excceed.
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        if(rowSum.size() == 0 || colSum.size() == 0) {
            return {};
        }
        
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++ i) {
            int v = rowSum[i]/m, mod = rowSum[i]%m;
            for(int j = 0; j < m; ++ j) {
                ans[i][j] = v;
            }
            ans[i][m - 1] += mod;
        }
        
        vector<long long> actualColSum(m, 0);
        for(int i = 0; i < m; ++ i) {
            for(int j = 0; j < n; ++ j) {
                actualColSum[i] += ans[j][i];
            }
        }
        
        for(int i = 0; i < m; ++ i) {
            if(colSum[i] == actualColSum[i]) {
                continue;
            }
            
            for(int j = i + 1; j < m; ++ j) {
                if(colSum[i] > actualColSum[i] && colSum[j] < actualColSum[j]) {
                    updateMtx(j, i, actualColSum[j] - colSum[j], colSum[i] - actualColSum[i], actualColSum, ans);
                } else if(colSum[i] < actualColSum[i] && colSum[j] > actualColSum[j]) {
                    updateMtx(i, j, actualColSum[i] - colSum[i], colSum[j] - actualColSum[j], actualColSum, ans);
                }
                
                if(colSum[i] == actualColSum[i]) {
                    break;
                }
            }
        }
        return ans;
    }
private:
    void updateMtx(int colPos, int colNeg, int pos, int neg, vector<long long> &colSum, vector<vector<int>> &ans) {
        int n = ans.size();
        for(int i = 0; i < n && pos > 0 && neg > 0; ++ i) {
            int v = pos;
            if(ans[i][colPos] >= pos) {
                ans[i][colPos] -= pos;
                pos = 0;
            } else {
                v = ans[i][colPos];
                pos -= ans[i][colPos];
                ans[i][colPos] = 0;
            }
            colSum[colPos] -= v;
            
            if(neg >= v) {
                ans[i][colNeg] += v;
                colSum[colNeg] += v;
                neg -= v;
            } else {
                v -= neg;
                ans[i][colPos] += v;
                ans[i][colNeg] += neg;
                colSum[colPos] += v;
                colSum[colNeg] += neg;
                
                neg = 0;
                pos += v;
            }
        }
        return ;
    }
};

// AC
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        if(rowSum.size() == 0 || colSum.size() == 0) {
            return {};
        }
        
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < m; ++ j) {
                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }

        return ans;
    }
};
