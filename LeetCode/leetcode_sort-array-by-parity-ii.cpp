/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(lgn)
*/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int fastPnt = 0;
        for(int i = 0; i < A.size(); ++ i){
            if((i%2 == 0 && A[i]%2 == 0) || (i%2 == 1 && A[i]%2 == 1)){
                fastPnt = max(fastPnt, i);
                continue;
            }
            while(fastPnt < A.size()){
                ++ fastPnt;
                if(i%2 == A[fastPnt]%2 ){
                    swap(A[i], A[fastPnt]);
                    break;
                }
            }
        }
        return A;
    }
};
