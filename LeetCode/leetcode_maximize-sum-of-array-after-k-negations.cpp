/*
*
* Tag: Greedy
* Time: O(nlgn + klgn)
* Space: O(n)
*/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.size() == 0) {
            return 0;
        }
        
        priority_queue<int,vector<int>, greater<int>> pq;
        int ans = 0;
        for(int i = 0; i < A.size(); ++ i) {
            ans += A[i];
            pq.push(A[i]);
        }
        
        for(int i = 0; i < K; ++ i) {
            int v = pq.top();
            pq.pop();
            
            ans -= 2*v;
            pq.push(-v);
        }
        return ans;
    }
};
