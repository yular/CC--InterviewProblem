/*
*
* Tag: Greedy
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        if(A.size() < 3) {
            return {-1, -1};
        }
        
        int tot = 0;
        for(int a : A) {
            tot += a;
        }
        if(tot%3 != 0) {
            return {-1, -1};
        }
        if(tot == 0) {
            return {0,2};
        }
        
        int mustZeroCnt = 0, n = A.size();
        for(int i = n - 1; i >= 0; -- i) {
            if(A[i] == 1) {
                break;
            }
            ++ mustZeroCnt;
        }
        
        int len = tot/3, partCnt = 0, cnt = 0;
        vector<int> ans = {-1, -1};
        for(int i = 0; i < A.size(); ++ i) {
            cnt += A[i];
            if(cnt == len) {
                bool isValid = true;
                for(int j = 1; j <= mustZeroCnt; ++ j) {
                    if(i + j >= n || A[i + j] == 1) {
                        isValid = false;
                        break;
                    }
                    
                }     
                if(!isValid) {
                    return {-1, -1};
                }
                
                i += mustZeroCnt;
                ans[partCnt] = i;
                if(partCnt == 1) {
                    ++ ans[partCnt];
                    break;
                }
                cnt = 0;
                ++ partCnt;
            }
        }
        
        if(isEqual(A, 0, ans[0], ans[0] + 1, ans[1] - 1, ans[1], A.size() - 1)) {
            return ans;
        }
        return {-1, -1};
    }
    
private:
    bool isEqual(vector<int>& arr, int idx1, int end1, int idx2, int end2, int idx3, int end3) {
        while(idx1 <= end1 && arr[idx1] == 0) {
            ++ idx1;
        }
        while(idx2 <= end2 && arr[idx2] == 0) {
            ++ idx2;
        }
        while(idx3 <= end3 && arr[idx3] == 0) {
            ++ idx3;
        }
        
        for(; idx1 <= end1 && idx2 <= end2 && idx3 <= end3; ++ idx1, ++ idx2, ++ idx3) {
            if(arr[idx1] != arr[idx2] || arr[idx1] != arr[idx3]) {
                return false;
            }
        }
        return idx1 > end1 && idx2 > end2 && idx3 > end3;
    }
};
