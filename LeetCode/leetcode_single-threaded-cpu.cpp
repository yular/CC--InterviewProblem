/*
*
* Tag: Data Structure
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    struct Task {
        long long ptime, etime;
        int idx;
        bool operator < (const Task &a)const{
            if(ptime == a.ptime) {
                return a.idx < idx;
            }
            return a.ptime < ptime;
        }
    };
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        if(tasks.size() == 0) {
            return {};
        }
        
        int n = tasks.size();
        vector<Task> tks(n);
        for(int i = 0; i < n; ++ i) {
            Task t;
            t.idx = i, t.etime = tasks[i][0], t.ptime = tasks[i][1];
            tks[i] = t;
        }
        
        sort(tks.begin(), tks.end(), cmp);
        
        long long curTime = tks[0].etime;
        int idx = 0;
        priority_queue<Task> pq;
        for(; idx < n; ++ idx) {
            if(tks[idx].etime > curTime) {
                break;
            }
            
            pq.push(tks[idx]);
        }
        
        vector<int> ans(n);
        int curIdx = 0;
        while(!pq.empty()) {
            Task t = pq.top();
            pq.pop();
            ans[curIdx ++] = t.idx;
            curTime = max(curTime + t.ptime, t.etime + t.ptime);
            
            for(; idx < n; ++ idx) {
                if(pq.empty() || curTime >= tks[idx].etime) {
                    pq.push(tks[idx]);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
private:
    struct comparator{
        bool operator() (const Task &a, const Task &b) {
            return a.etime < b.etime;
        }
    }cmp;
};
