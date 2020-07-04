/*
*
* Tag: Data Structure
* Time: O(n^3)
* Space: O(n)
*/

class Solution {
private:
    struct webPattern {
        string username, website;
        int timestamp;
    };
    
    struct comparator {
        bool operator() (const webPattern &a, const webPattern &b) {
            return a.timestamp < b.timestamp;
        }
    }cmp;
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        if(username.size() == 0 || timestamp.size() < 3) {
            return {};
        }
    
        vector<webPattern> arr(username.size());
        for(int i = 0; i < username.size(); ++ i) {
            webPattern p;
            p.username = username[i], p.timestamp = timestamp[i], p.website = website[i];
            arr[i] = p;
        }
        
        sort(arr.begin(), arr.end(), cmp);
        
        unordered_map<string,vector<string>> userVisitDic; 
        for(int i = 0; i < arr.size(); ++ i) {
            userVisitDic[arr[i].username].push_back(arr[i].website);
        }
        
        unordered_map<string,int> visitPatternCnt;
        int maxCnt = 0;
        string maxPattern = "";
        vector<string> ans;
        for(auto it = userVisitDic.begin(); it != userVisitDic.end(); it ++){
            vector<string> webSites = it->second;
            int n = webSites.size();
            unordered_set<string> vis;
            for(int i = 0; i < n -2; ++ i) {
                for(int j = i + 1; j < n - 1; ++ j) {
                    for(int k = j + 1; k < n; ++ k) {
                        string curPattern = webSites[i] + "," + webSites[j] + "," + webSites[k];
                        if(vis.count(curPattern) > 0) {
                            continue;
                        }
                        
                        vis.insert(curPattern);
                        ++ visitPatternCnt[curPattern];
                        
                        if(visitPatternCnt[curPattern] > maxCnt || (visitPatternCnt[curPattern] == maxCnt && curPattern <  maxPattern) ) {
                            maxCnt = visitPatternCnt[curPattern];
                            maxPattern = curPattern;
                            ans = {webSites[i], webSites[j], webSites[k]};
                        }
                    }
                }
            }
        }
        return ans;
    }
};
