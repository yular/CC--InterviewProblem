/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(1)
*/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(code.size() == 0) {
            return code;
        }
        
        int sum = 0, n = code.size(), K = abs(k);
        if(k > 0) {
            for(int i = 1; i <= k; ++ i) {
                sum += code[i];
            }
        } else if(k < 0) {
            for(int i = n - 1; K > 0; -- i, -- K) {
                sum += code[i];
            }
        }
        
        vector<int> ans(n, 0);
        if(k == 0) {
            return ans;
        }
        
        for(int i = 0; i < n; ++ i) {
            ans[i] = sum;
            
            if(k > 0) {
                int idx = (i + 1 + k)%n;
                sum += code[idx];
                if(i + 1 < n) {
                    sum -= code[i + 1];
                }
            } else {
                sum += code[i];
                int idx = (i - abs(k) + n)%n;
                sum -= code[idx];
            }
        }
        return ans;
    }
};
