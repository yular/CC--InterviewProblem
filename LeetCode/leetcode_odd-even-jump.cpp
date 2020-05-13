/*
*
* Tag: DFS
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        if(A.size() < 2) {
            return A.size();
        }
        
        int n = A.size();
        vector<int> oddAccess(n, -1), evenAccess(n, -1);
        vector<int> stk(n + 1, 0);
        int top = 0;
        for(int i = n - 1; i >= 0; -- i) {
            while(top > 0 && A[i] > A[stk[top - 1]]) {
                -- top;
            }
            if(top > 0) {
                oddAccess[i] = stk[top - 1];
            }
            stk[top ++] = i;
        }
        
        top = 0;
        for(int i = n - 1; i >= 0; -- i) {
            while(top > 0 && A[i] < A[stk[top - 1]]) {
                -- top;
            }
            if(top > 0) {
                evenAccess[i] = stk[top - 1];
            }
            stk[top ++] = i;
        }
        
        int ans = 1;
        vector<vector<int>> canReach(n, vector<int>(2, -1));
        canReach[n - 1][0] = canReach[n - 1][1] = 1;
        for(int i = n - 2; i >= 0; -- i) {
            if(oddAccess[i] == n - 1) {
                ++ ans;
                canReach[i][1] = 1;
                continue;
            }
            if(oddAccess[i] == -1) {
                canReach[i][1] = 0;
                continue;
            }
            
            jump(i, n - 1, 1, canReach, oddAccess, evenAccess);
            if(canReach[i][1] == 1) {
                ++ ans;
            }
        }
        return ans;
    }
private:
    void jump(int cur, int dst, int dep, vector<vector<int>> &canReach, vector<int> &oddAccess,vector<int> & evenAccess) {
        if(cur > dst || cur < 0) {
            return ;
        }
        
        int idx = dep&1;
        int nxt = idx == 1? oddAccess[cur] : evenAccess[cur];
        if(nxt == dst) {
            canReach[cur][idx] = 1;
            return;
        }
        if(nxt == -1) {
            canReach[cur][idx] = 0;
            return ;
        }
        if(canReach[nxt][(idx + 1)%2] != -1) {
            canReach[cur][idx] = canReach[nxt][(idx + 1)%2];
            return ;
        }
        
        jump(nxt, dst, dep + 1, canReach, oddAccess, evenAccess);
        canReach[cur][idx] = canReach[nxt][(idx + 1)%2];
        return ;
    }
};
