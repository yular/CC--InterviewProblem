/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> numCnt;
        for(int v : arr) {
            ++ numCnt[v%k];
        }
        
        if(numCnt.count(0) > 0 && numCnt[0]%2 != 0) {
            return false;
        }
        
        vector<pair<int,int>> divArr(numCnt.begin(), numCnt.end());
        sort(divArr.begin(), divArr.end(), cmp);
        
        for(int i = 0; i < divArr.size(); ++ i) {
            int div = divArr[i].first;
            if(numCnt.count(div) == 0) {
                continue;
            }
            
            if(div == 0) {
                numCnt.erase(div);
                continue;
            }
            
            int cnt = numCnt[div];
            int rest = div < 0 ? -k - div : k - div;
            if(numCnt.count(rest) > 0 && numCnt[rest] >= cnt) {
                numCnt[rest] -= cnt;
                if(numCnt[rest] == 0) {
                    numCnt.erase(rest);
                }
                numCnt.erase(div);
                continue;
            }
            
            rest = -div;
            if(numCnt.count(rest) > 0 && numCnt[rest] >= cnt) {
                numCnt[rest] -= cnt;
                if(numCnt[rest] == 0) {
                    numCnt.erase(rest);
                }
                numCnt.erase(div);
            }
        }
        return numCnt.size() == 0;
    }
    
private:
    struct comparator {
        bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
            return a.second < b.second;
        }
    }cmp;
};
