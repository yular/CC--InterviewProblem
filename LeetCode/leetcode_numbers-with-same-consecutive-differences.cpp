/*
*
* Tag: Data Structure, Queue
* Time: O(k*2^n)
* Space: O(2^n)
*/

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 0) {
            return {};
        }
        if(N == 1) {
            return {0,1,2,3,4,5,6,7,8,9};
        }
        
        queue<long long> q;
        for(int i = 1; i < 10; ++ i) {
            if(i - K >= 0 || i + K < 10) {
                q.push(i);
            }
        }
        
        for(int i = 1; i < N; ++ i) {
            queue<long long> curq;
            while(!q.empty()) {
                long long cur = q.front();
                q.pop();
                
                int v = cur%10;
                if(v + K < 10) {
                    long long nxt = cur*10 + (v + K);
                    curq.push(nxt);
                }
                if(v - K >= 0 && K != 0) {
                    long long nxt = cur*10 + (v - K);
                    curq.push(nxt);
                }
            }
            q = curq;
        }
        
        vector<int> ans(q.size());
        int idx = 0;
        while(!q.empty()) {
            ans[idx ++] = q.front();
            q.pop();
        }
        return ans;
    }
};
