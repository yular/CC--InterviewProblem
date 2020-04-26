/*
*
* Tag: BFS + Sort
* Time: O(n^2) + O(mlgm)
* Space: O(n)
*/

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        if(watchedVideos.size() == 0 || friends.size() == 0) {
            return {};
        }
        
        unordered_map<int,vector<int>> g;
        for(int i = 0; i < friends.size(); ++ i) {
            vector<int> f = friends[i];
            for(int j = 0; j < f.size(); ++ j) {
                g[i].push_back(f[j]);
            }
        }
        
        queue<int> q;
        q.push(id);
        unordered_set<int> vis;
        vis.insert(id);
        
        for(int i = 0; i < level; ++ i) {
            queue<int> nxtq;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v : g[u]) {
                    if(vis.count(v) != 0) {
                        continue;
                    }
                    
                    nxtq.push(v);
                    vis.insert(v);
                }
            }
            q = nxtq;
        }
        
        unordered_map<string,int> videoCnt;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(string video : watchedVideos[u]) {
                ++ videoCnt[video];
            }
        }
        
        vector<pair<string,int>> vset(videoCnt.size());
        int idx = 0;
        for(auto it : videoCnt) {
            vset[idx ++] = make_pair(it.first, it.second);
        }
        
        sort(vset.begin(), vset.end(), cmp);
        
        vector<string> ans(vset.size());
        idx = 0;
        for(pair<string,int> v : vset) {
            ans[idx ++] = v.first;
        }
        return ans;
    }
private:
    struct comparator{
        bool operator() (const pair<string,int> &a, const pair<string,int> &b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    }cmp;
};
