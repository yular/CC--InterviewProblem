/*
*
* Tag: BFS
* Time: O(n*m) n is the number of links and m is the average length of link string.
* Space: O(n)
*/
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> ans;
        if(startUrl.size() == 0) {
            return ans;
        }
        
        unordered_set<string> vis = {startUrl};
        queue<string> q;
        q.push(startUrl);
        string curHostName = getHostName(startUrl);
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            ans.push_back(cur);
            
            vector<string> urls = htmlParser.getUrls(cur);
            for(string url : urls){
                if(vis.count(url) > 0){
                    continue;
                }
                if(getHostName(url) != curHostName) {
                    continue;
                }
                
                vis.insert(url);
                q.push(url);
            }
        }
        
        return ans;
    }
private:
    string getHostName(string url) {
        string res = "";
        bool canAppend = false;
        for(int i = 0; i < url.size() && url[i] != '/'; ++ i){
            if(url[i] == ':') {
                i += 2;
                canAppend = true;
                continue;
            }
            if(!canAppend) {
                continue;
            }
            
            res += url[i];
        }
        return res;
    }
};
