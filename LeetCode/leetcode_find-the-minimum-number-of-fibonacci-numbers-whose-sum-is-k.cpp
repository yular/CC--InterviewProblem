/*
*
* Tag: Greedy
* Time: O(n^(0.33333))
* Space: O(n^(0.33333))
*/

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        set<int> st = {1, 1};
        int a = 1, b = 1, sum = 0;
        for(; sum < k; ) {
            sum = a + b;
            st.insert(sum);
            a = b, b = sum;
        }

        int cnt = 0;
        while(k > 0) {
            auto it = st.lower_bound(k);
            ++ cnt;
            if(*it == k) {
                break;
            }
            it --;
            k -= *it;
        }
        return cnt;
    }
};
