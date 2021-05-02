/*
*
* Tag: Sort + Greedy
* Time: O(nlgn + mlgm + mlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        if(queries.size() == 0) {
            return {};
        }
        
        sort(rooms.begin(), rooms.end(), cmpRM);
        
        int n = rooms.size(), m = queries.size();
        vector<vector<int>> q(m);
        for(int i = 0; i < m; ++ i) {
            q[i] = {i, queries[i][0], queries[i][1]};
        }
        sort(q.begin(), q.end(), cmpQ);
        
        vector<int> ans(m, 0);
        set<int> ids;
        for(int i = 0, j = 0; i < m; ++ i) {
            int id = q[i][0];
            if(q[i][2] > rooms[0][1]) {
                ans[id] = -1;
                continue;
            }
            
            while(j < n && rooms[j][1] >= q[i][2]) {
                ids.insert(rooms[j][0]);
                ++ j;
            }
            
            int maxId = *ids.rbegin();
            if(q[i][1] >= maxId){
                ans[id] = maxId;
                continue;
            }
            
            auto it = ids.lower_bound(q[i][1]);
            int diff = abs(*it - q[i][1]);
            if(diff == 0 || ids.size() == 1 || it == ids.begin()) {
                ans[id] = *it;
                continue;
            }
            
            ans[id] = *it;
            it --;
            if(diff >= abs(*it - q[i][1])) {
                ans[id] = *it;
            }
        }
        return ans;
    }
    
private:
    struct comparatorRoom {
        bool operator() (vector<int> &a, vector<int> &b) {
            if(a[1] == b[1]) {
                return a[0] < b[0];
            }
            return b[1] < a[1];
        }
    }cmpRM;
    
    struct comparatorQ {
        bool operator() (vector<int> &a, vector<int> &b) {
            return b[2] < a[2];
        }
    }cmpQ;
};
