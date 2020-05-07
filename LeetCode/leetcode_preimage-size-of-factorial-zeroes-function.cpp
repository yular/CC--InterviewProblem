/*
*
* Tag: Binary Search
* Time: O(1) or O(lgn)
* Space: O(1)
*/

class Solution {
public:
    int preimageSizeFZF(int K) {
        if(K == 0) {
            return 5;
        }
        
        long long l = 1, r = 1L<<33, ansr = -1;
        while(l <= r) {
            long long mid = (l + r)>>1;
            long long v = func(mid);
            if(v <= K) {
                if(v == K) {
                    ansr = mid;
                }
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if(ansr == -1) {
            return 0;
        }
        
        long long ansl = -1;
        l = 1, r = 1L<<33;
        while(l <= r) {
            long long mid = (l + r)>>1;
            long long v = func(mid);
            if(v >= K) {
                if(v == K) {
                    ansl = mid;
                }
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ansr - ansl + 1;
    }
private:
    long long func(long long x) {
        long long cnt = 0;
        while(x > 0) {
            cnt += x/5;
            x /= 5;
        }
        return cnt;
    }
};
