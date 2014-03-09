/*
* Algorithm: brute force, bit operation
* Time complexity: O(n)
* Memory complexity: O(n)
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans = 0;
        ans = A[0];
        for(int i = 1; i < n; i ++)
            ans ^= A[i];
        return ans;
    }
};

