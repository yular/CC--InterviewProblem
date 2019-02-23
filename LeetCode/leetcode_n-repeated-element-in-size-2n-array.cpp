/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> vis;
        int ans = A[0];
        for(int v : A){
            if(vis.count(v) != 0){
                ans = v;
                break;
            }
            vis.insert(v);
        }
        
        return ans;
    }
};

/*
*
* Tag: Math
* Time: O(n)
* Space: O(1)
*/
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int ans = 0;
        for(int k = 1; k <= 3; ++ k){
            for(int i = 0; i < A.size() - k; ++ i){
                if(A[i] == A[i + k]) {
                    return A[i];
                }
            }
        }
        
        return ans;
    }
};
