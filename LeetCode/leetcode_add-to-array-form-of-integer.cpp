/*
*
* Tag: Implementation
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> k = intToVector(K);
        if(A.size() == 0){
            return k;
        }
        
        vector<int> ans;
        int c = 0, idxA = A.size() - 1, idxK = k.size() - 1;
        for(; idxA >= 0 && idxK >= 0; -- idxA, -- idxK){
            int v = A[idxA] + k[idxK] + c;
            ans.push_back(v%10);
            c = v/10;
        }
        
        while(idxA >= 0){
            int v = A[idxA] + c;
            -- idxA;
            ans.push_back(v%10);
            c = v/10;
        }
        while(idxK >= 0){
            int v = k[idxK] + c;
            -- idxK;
            ans.push_back(v%10);
            c = v/10;
        }
        if(c > 0){
            ans.push_back(1);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    vector<int> intToVector(int v){
        vector<int> ans;
        if(v == 0){
            ans.push_back(v);
            return ans;
        }
        
        while(v > 0) {
            ans.push_back(v%10);
            v /= 10;
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
