/*
*
* Tag: Sort
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        if(arr.size() == 0) {
            return arr;
        }
        
        vector<pair<int,int>> bitArr(arr.size());
        for(int i = 0; i < arr.size(); ++ i){
            bitArr[i] = make_pair(arr[i], countBit(arr[i]));
        }
        
        sort(bitArr.begin(), bitArr.end(), cmp);
        
        for(int i = 0; i < arr.size(); ++ i){
            arr[i] = bitArr[i].first;
        }
        return arr;
    }
    
private:
    struct chainComparator{
        bool operator() (const pair<int,int> &a, const pair<int,int> &b){
            return a.second == b.second? a.first < b.first : a.second < b.second;
        }
    }cmp;
    
    int countBit(int v) {
        int res = 0;
        while(v > 0) {
            res += (v&1);
            v >>= 1;
        }
        return res;
    }
};
