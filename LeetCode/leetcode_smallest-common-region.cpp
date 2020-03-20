/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        if(regions.size() == 0) {
            return "";
        }
        
        unordered_map<string,string> parentRegion;
        for(vector<string> region : regions) {
            for(int i = region.size() - 1; i >= 1; -- i) {
                parentRegion[region[i]] = region[0];
            }
        }
        
        string curReg1 = region1, curReg2 = region2;
        unordered_set<string> vis = {region1, region2};
        while(curReg1 != curReg2) {
            curReg1 = parentRegion[curReg1];
            curReg2 = parentRegion[curReg2];
            if(curReg1 != "" && vis.count(curReg1) > 0) {
                return curReg1;
            }
            if(curReg2 != "" && vis.count(curReg2) > 0) {
                return curReg2;
            }
            
            if(curReg1 != "") {
                vis.insert(curReg1);
            }
            if(curReg2 != "") {
                vis.insert(curReg2);
            }
        }
        return curReg2;
    }
};
