/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(1)
*/
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        if(n == 0){
            return -1;
        }
        
        vector<pair<int,int>> waterRanges;
        for(int i = 0; i < ranges.size(); ++ i){
            if(ranges[i] == 0){
                continue;
            }
            int leftBnd = max(0, i - ranges[i]), rightBnd = min(n, i + ranges[i]);
            waterRanges.push_back(make_pair(leftBnd, rightBnd));
        }
        if(waterRanges.size() == 0){
            return -1;
        }
        
        sort(waterRanges.begin(), waterRanges.end(), cmp);
        if(waterRanges[0].first != 0){
            return -1;
        }
        
        int curRightBnd = waterRanges[0].second, nxtRightBnd = waterRanges[0].second;
        int ans = 1;
        if(curRightBnd >= n){
            return ans;
        }
        for(int i = 1; i < waterRanges.size();){
            while(i < waterRanges.size()){
                if(waterRanges[i].first > curRightBnd || curRightBnd >= n) {
                    break;
                }
                nxtRightBnd = max(nxtRightBnd, waterRanges[i].second);
                ++ i;
            }
            ++ ans;
            curRightBnd = nxtRightBnd;
            if(i >= waterRanges.size() || curRightBnd >= n){
                break;
            }
            if(waterRanges[i].first > curRightBnd) {
                return -1;
            }
        }
        if(curRightBnd < n) {
            return -1;
        }
        return ans;
    }
    
private:
    struct comparator {
        bool operator() (const pair<int,int> &a, const pair<int,int> &b){
            return a.first == b.first ? b.second < a.second : a.first < b.first;
        }
    }cmp;
};
