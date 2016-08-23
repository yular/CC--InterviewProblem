/*
*
* Tag: String
* Time: O(n) (Manacher)
* Space: O(n)
*/
#include <vector>
int solution(string &S) {
    int res = 0, n = (int)S.size(), len = 0;
    if (n <= 1) {
        return 0;
    }
    string s1;
    s1.resize(2*n + 2);
    vector<int> p(2*n + 2, 0);
    s1[0] = '$', s1[1] = '#';
    for (int i = 0; i < n; ++ i) {
        s1[(i + 1)<<1] = S[i];
        s1[((i + 1)<<1) + 1] = '#';
    }
    int c = 0,r = 0;
    for (int i = 1; i < s1.size(); ++ i) {
        int idx = 2*c - i;
        if (r > i) {
            p[i] = min(r - i, p[idx]);
        }else{
            p[i] = 0;
        }
        while (s1[p[i] + i + 1] == s1[i - 1 - p[i]]) {
            ++ p[i];
        }
        res += p[i]/2;
        if (res > 100000000) {
            return -1;
        }
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    return res;
}
