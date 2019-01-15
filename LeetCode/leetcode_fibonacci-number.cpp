/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int fib(int N) {
        if(N < 2){
            return N;
        }
        int pre = 0, cur = 1;
        for(int i = 2; i <= N; ++ i){
            int nxt = pre + cur;
            pre = cur;
            cur = nxt;
        }
        return cur;
    }
};
