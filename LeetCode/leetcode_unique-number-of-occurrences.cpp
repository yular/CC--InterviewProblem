/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> numCnt;
        unordered_set<int> cntDict;
        
        for(int num : arr){
            ++ numCnt[num];
        }
        for(pair<int,int> cnt : numCnt){
            if(cntDict.count(cnt.second) > 0){
                return false;
            }
            cntDict.insert(cnt.second);
        }
        
        return true;
    }
};
