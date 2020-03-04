/*
*
* Tag: DFS
* Time: O(n^n)
* Space: O(n!)
*/

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> seqset;
        
        vector<bool> vis(tiles.size(), false);
        string str = "";
        dfs(seqset, tiles, str, vis);
        
        return (int)seqset.size();
    }
private:
    void dfs(unordered_set<string> &seqset, string &tiles, string &str, vector<bool> &vis){
        for(int i = 0; i < tiles.size(); ++ i){
            if(vis[i]) {
                continue;
            }
            string nxt = str + tiles[i];
            if(seqset.count(nxt) > 0) {
                continue;
            }
            
            vis[i] = true;
            seqset.insert(nxt);
            dfs(seqset, tiles, nxt, vis);
            vis[i] = false;
        }
        
        return;
    }
};
