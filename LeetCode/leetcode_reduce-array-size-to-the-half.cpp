/*
*
* Tag: Greedy
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        if(arr.size() <= 2) {
            return arr.size()/2;
        }
        
        int ans = 0;
        unordered_map<int,int> numCnt;
        for(int v : arr){
            ++ numCnt[v];
        }
        
        vector<pair<int,int>> cntVec(numCnt.size());
        int i = 0;
        for(pair<int,int> cnt : numCnt){
            cntVec[i] = cnt;
            ++ i;
        }
        
        sort(cntVec.begin(), cntVec.end(), cmp);
        
        int cnt = 0;
        for(pair<int,int> v : cntVec) {
            cnt += v.second;
            ++ ans;
            if(cnt >= arr.size()/2) {
                break;
            }
        }
        return ans;
    }
private:
    struct comparator {
        bool operator () (const pair<int,int> &a, const pair<int,int> &b){
            return b.second < a.second;
        }
    }cmp;
};
