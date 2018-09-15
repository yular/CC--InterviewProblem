/*
*
* Tag: DFS
* Time: O(n + m) where n is the number of nodes and m is the number of edges
* Space: O(n + m)
*/

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if(N < 2){
            return true;
        }
        
        unordered_map<int, unordered_set<int>> dislikeRelation;
        for(vector<int> dislike : dislikes){
            dislikeRelation[dislike[0]].insert(dislike[1]);
            dislikeRelation[dislike[1]].insert(dislike[0]);
        }
        
        vector<int> nodeColor(N + 1, -1);
        for(int i = 1; i <= N; ++ i){
            if(nodeColor[i] == -1 && !dfs(i, 0, N, dislikeRelation, nodeColor)) {
                return false;
            }
        }
        
        return true;
    }
private:
    bool dfs(int curNode, int color, int N, unordered_map<int, unordered_set<int>> &dislikeRelation, vector<int> &nodeColor) {
        nodeColor[curNode] = color;
        
        for(int nextNode : dislikeRelation[curNode]) {
            if(nodeColor[nextNode] == nodeColor[curNode]) {
                return false;
            }
            
            if(nodeColor[nextNode] == -1 && !dfs(nextNode, (color+1)%2, N, dislikeRelation, nodeColor)) {
                return false;
            }
        }
        
        return true;
    }
};
