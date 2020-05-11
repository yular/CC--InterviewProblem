/*
*
* Tag: Silding Window
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size() < 2) {
            return A.size();
        }
        if(A.size() == 2) {
            return A[0] == A[1] ? 1 : 2;
        }
        
        int sum = 0, l = 0, ans = 1;
        if(A[1] == A[0]) {
            l = 1;
        } else {
            sum = A[1] > A[0] ? 1 : -1;
            ans = 2;
        }
        
        int n = A.size();
        for(int r = 2; r <= n; ++ r) {
            int v = A[min(r, n - 1)];
            if(v > A[r - 1]) {
                ++ sum;
            } else if(v < A[r - 1]) {
                -- sum;
            }

            if(v == A[r - 1] || abs(sum) > 0) {
                ans = max(ans, r - l);
                if(abs(sum) >= 2) {
                    l = r - 1;
                    sum = A[r] > A[l] ? 1 : -1;
                } else {
                    if(r == n) {
                        break;
                    }
                    
                    sum = 0;
                    l = r;
                    if(A[r + 1] > v) {
                        ++ sum;
                    } else if(A[r + 1] < v) {
                        -- sum;
                    }
                }
                continue;
            }
            ans = max(ans, r - l + 1);
            sum = v > A[r - 1] ? 1 : -1;
        }
        return ans;
    }
};
