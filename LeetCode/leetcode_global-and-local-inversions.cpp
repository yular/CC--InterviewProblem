/*
*
* Tag: Data Structure Fenwick tree
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        if(A.size() < 2) {
            return true;
        }
       
        int localInvCnt = 0;
        for(int i = 0; i < A.size() - 1; i ++) {
            if(A[i] > A[i + 1]) {
                ++ localInvCnt;
            }
        }
       
        int globalInvCnt = 0;
        vector<int> fenWick(A.size() + 1, 0);
        for(int i = A.size() - 1; i >= 0; -- i) {
            int v = A[i] + 1;
            globalInvCnt += countInv(fenWick, v);
            if(globalInvCnt > localInvCnt) {
                break;
            }
            updateFenWick(fenWick, v);
        }
       
        return globalInvCnt == localInvCnt;
    }
private:
    int countInv(vector<int> &fenWick, int v) {
        int res = 0;
        for(int i = v; i > 0; i -= lowbit(i)) {
            res += fenWick[i];
        }
        return res;
    }
   
    void updateFenWick(vector<int> &fenWick, int v) {
        for(int i = v; i < fenWick.size(); i += lowbit(i)) {
            ++ fenWick[i];
        }
    }
   
    int lowbit(int x) {
        return x&-x;
    }
};
