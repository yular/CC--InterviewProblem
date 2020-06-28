/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int,unordered_set<int>> vis;
        int r = 0, c = 0;
        vis[r].insert(c);
        for(char op : path) {
            updateLoc(op, r, c);
            if(vis.count(r) > 0 && vis[r].count(c) > 0) {
                return true;
            }
            vis[r].insert(c);
        }
        return false;
    }
private:
    void updateLoc(char op, int &r, int &c) {
        switch(op) {
            case 'N':
                -- r;
                break;
            case 'S':
                ++ r;
                break;
            case 'E':
                ++ c;
                break;
            case 'W':
                -- c;
        }
        
        return ;
    }
};
