/*
* Algorithm: Brute force, Bit manipulation
* Time complexity: O(n)
* Memory complexity: O(n)
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        const int M = sizeof(int)*8;
        int cnt[M];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < M; j ++){
                cnt[j] += ((A[i]>>j)&1);
                cnt[j] %= 3;
            }
        }
        int res = 0;
        for(int i = 0; i < M; i ++){
            res += (cnt[i]<<i);
        }
        return res;
    }
};

