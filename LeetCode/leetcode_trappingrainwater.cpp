/*
* Algorithm: Brute force
* Time complexity: O(n)
* Memory complexity: O(1)
*/
class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 0) return 0;
        int ans = 0;
        for(int i = 0; i < n; i ++){
            if(!A[i]) continue;
            int sum = 0;
            for(int j = i + 1; j < n; j ++){
                if(A[j] >= A[i]) {
                    ans += sum;
                    i = j - 1;
                    break;
                }else if(j < n - 1){
                    sum += (A[i] - A[j]);
                }else if(j == n - 1){
                    ans += revers(i,j,A);
                    i = j;
                }
            }
        }
        return ans;
    }
    
    int revers(int sta,int ends,int A[]){
        int sum = 0;
        for(int i = ends - 1; i >= sta; i --){
            if(A[i] >= A[ends]){
                ends = i;
            }else{
                sum += (A[ends] - A[i]);
            }
        }
        return sum;
    }
};
