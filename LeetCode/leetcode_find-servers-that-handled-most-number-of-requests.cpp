/*
*
* Tag: Data Structure
* Time: O(klgk + nlgk)
* Space: O(k)
*/

class Solution {
private:
    struct node {
        int idx, time;
        bool operator < (const node &a)const{
            return a.time < time;
        }
    };
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        if(k <= 0 || arrival.size() == 0 || arrival.size() != load.size()) {
            return {};
        }
        
        set<int> hosts;
        vector<int> reqCnt(k, 0);
        for(int i = 0; i < k; ++ i) {
            hosts.insert(i);
            reqCnt[i] = 0;
        }
        
        priority_queue<node> pq;
        int n = arrival.size(), maxCnt = 0;
        for(int i = 0; i < n; ++ i) {
            int t = arrival[i] - 1;
            while(!pq.empty()) {
                node cur = pq.top();
                if(cur.time > t) {
                    break;
                }
                
                pq.pop();
                hosts.insert(cur.idx);
            }
            
            if(hosts.empty()) {
                continue;
            }
            
            int idx = (i%k);
            auto it = hosts.lower_bound(idx);
            if(it == hosts.end()) {
                it = hosts.begin();
            }
            
            idx = *it;
            ++ reqCnt[idx];
            maxCnt = max(maxCnt, reqCnt[idx]);
            
            node nd;
            nd.idx = idx, nd.time = t + load[i];
            pq.push(nd);
            hosts.erase(idx);
        }
        
        vector<int> ans;
        for(int i = 0; i < k; ++ i) {
            if(reqCnt[i] == maxCnt) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
