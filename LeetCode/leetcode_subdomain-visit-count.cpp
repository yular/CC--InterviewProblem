/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n^2)
*/
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        if(cpdomains.size() == 0) {
            return {};
        }
        
        unordered_map<string,int> domainCnt;
        for(string domain : cpdomains) {
            int cnt = 0, i = 0;
            while(i < domain.size() && domain[i] >= '0' && domain[i] <= '9') {
                cnt = cnt*10 + (domain[i] - '0');
                ++ i;
            }
            ++ i;
            
            domainCnt[domain.substr(i)] += cnt;
            for(; i < domain.size(); ++ i) {
                if(domain[i] != '.') {
                    continue;
                }
                
                ++ i;
                string dm = domain.substr(i);
                domainCnt[dm] += cnt;
            }
        }
        
        vector<string> ans;
        for(pair<string,int> cnt : domainCnt) {
            string tmp = to_string(cnt.second) + " " + cnt.first;
            ans.push_back(tmp);
        }
        return ans;
    }
};
