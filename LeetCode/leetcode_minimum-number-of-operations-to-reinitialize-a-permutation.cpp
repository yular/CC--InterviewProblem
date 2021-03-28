/*
*
* Tag: Brute Force / implementation
* Time: O(n^2)
* Space: O(n)
*/

class Solution {
public:
    int reinitializePermutation(int n) {
        if(n < 2) {
            return n;
        }
        
        vector<int> perm(n, 0), arr(n, 0);
        for(int i = 1; i < n; ++ i){
            perm[i] = i;
        }
        
        int ans = 0;
        for(int i = 0; i < n; ++ i) {
            for(int j = 1; j < n; ++ j) {
                if((j&1) == 0) {
                    arr[j] = perm[j/2];
                } else {
                    arr[j] = perm[n/2 + (j - 1)/2];
                }
            }
            
            perm = arr;
            ++ ans;
            bool isDone = true;
            for(int j = 1; j < n; ++ j) {
                if(perm[j] != j) {
                    isDone = false;
                    break;
                }
            }
            if(isDone) {
                break;
            }
        }
        return ans;
    }
};
