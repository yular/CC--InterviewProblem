/*
*
* Tag: DP
* Time: O(n*max(abs(A[i]))^2)
* Space: O(max(abs(A[i]))^2)
*/
// you can use includes, for example:
// #include <algorithm>
#include <climits>

int solution(vector<int> &A){
    if(A.size() == 0)
        return 0;
    int res = INT_MAX, v;
    vector<bool> predp, curdp;
    int sz = 0;
    for (int i = 0; i < A.size(); ++ i) {
        sz = max(sz, abs(A[i]));
    }
    curdp.resize((sz<<1) + 10);
    curdp[sz - abs(A[0])] = curdp[sz + abs(A[0])] = true;
    predp = curdp;
    for (int i = 1; i < A.size(); ++ i) {
        fill(curdp.begin(), curdp.end(), false);
        for (int j = 0; j <= 2*sz; ++ j) {
            if (predp[j]) {
                v = j - abs(A[i]);
                if (v >= 0) {
                    curdp[v] = 1;
                }
                v = j + abs(A[i]);
                if (v <= 2*sz) {
                    curdp[v] = 1;
                }
            }
        }
        predp = curdp;
    }
    for (int i = 0; i <= 2*sz; ++ i) {
        if (curdp[i]) {
            res = min(res, abs(i - sz));
        }
    }
    return res;
}
