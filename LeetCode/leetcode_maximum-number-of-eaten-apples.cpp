/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    struct node {
        int cnt, t;
        bool operator < (const node &a)const{
            return a.t < t;
        }
    };
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        if(apples.size() != days.size()) {
            return 0;
        }
        
        priority_queue<node> pq;
        int ans = 0, n = apples.size(), i = 0;
        for(; i < n; ++ i) {
            if(apples[i] != 0) {
                node nd;
                nd.cnt = apples[i], nd.t = i + days[i];
                pq.push(nd);
            }
            while(!pq.empty()) {
                node cur = pq.top();
                if(cur.t <= i) {
                    pq.pop();
                    continue;
                }
                break;
            }
            if(!pq.empty()) {
                node cur = pq.top();
                pq.pop();
                ++ ans;
                -- cur.cnt;
                if(cur.cnt > 0) {
                    pq.push(cur);
                }
            }
        }
        
        for(;!pq.empty(); ++ i) {
            node cur = pq.top();
            pq.pop();
            if(cur.t <= i) {
                -- i;
                continue;
            }
            int v = min(cur.t - i, cur.cnt);
            ans += v;
            i += v - 1;
        }
        return ans;
    }
};
