/*
*
* Tag: Greedy, Array
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.size() != B.size() || A.size() == -1) {
            return -1;
        }
        
        int ansA = getMinRotations(A, B), ansB = getMinRotations(B, A);
        int ans = -1;
        if(ansA != -1) {
            ans = ansA;
        }
        if(ansB != -1) {
            ans = ans == -1? ansB : min(ans, ansB);
        }
        
        return ans;
    }
private:
    int getMinRotations(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int res = n + 1;
        for(int i = 1; i <= 6; ++ i) {
            bool isPossible = true;
            int cnt = 0;
            for(int j = 0; j < n; ++ j) {
                if(a[j] == i) {
                    continue;
                }
                if(b[j] != i) {
                    isPossible = false;
                    break;
                }
                ++ cnt;
            }
            if(!isPossible) {
                continue;
            }
            
            res = min(res, cnt);
        }
        return res == n + 1 ? -1 : res;
    }
};
