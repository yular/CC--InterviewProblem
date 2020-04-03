/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        if(arr.size() < 2) {
            return false;
        }
        
        unordered_set<int> vis = {arr[0]};
        for(int i = 1; i < arr.size(); ++ i){
            if(vis.count(arr[i]*2) > 0 || (arr[i]%2 == 0 && vis.count(arr[i]/2) > 0)) {
                return true;
            }
            vis.insert(arr[i]);
        }
        return false;
    }
};
