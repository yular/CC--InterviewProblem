/*
*
* Tag: Hash + Sort
* Time: O(m + nlgn)
* Space: O(n + m)
*/

class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        if(features.size() == 0) {
            return features;
        }
        
        unordered_map<string,int> wdCnt;
        unordered_map<string,int> wdIdx;
        for(int i = 0; i < features.size(); ++ i) {
            string f = features[i];
            wdCnt[f] = 0;
            wdIdx[f] = i;
        }
        
        unordered_set<string> vis;
        for(string resp : responses) {
            string wd = "";
            for(int i = 0; i < resp.size(); ++ i) {
                if(resp[i] == ' ' || i == resp.size() - 1) {
                    if(resp[i] != ' ') {
                        wd += resp[i];
                    }
                    if(wdCnt.count(wd) > 0 && vis.count(wd) == 0) {
                        ++ wdCnt[wd];
                        vis.insert(wd);
                    }
                    wd = "";
                } else {
                    wd += resp[i];
                }
            }
            vis.clear();
        }
        
        vector<pair<int,int>> wdlist(features.size());
        int idx = 0;
        for(pair<string,int> p : wdCnt) {
            if(wdCnt.count(p.first) > 0) {
                wdlist[idx ++] = {wdIdx[p.first], p.second};
            }
        }
        
        sort(wdlist.begin(), wdlist.end(), cmp);
        
        vector<string> ans = features;
        for(int i = 0; i < wdlist.size(); ++ i) {
            ans[i] = features[wdlist[i].first];
        }
        return ans;
    }
private:
    struct comparator {
        bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
            if(a.second == b.second) {
                return a.first < b.first;
            }
            return b.second < a.second;
        }
    }cmp;
};
