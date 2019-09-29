/*
*
* Tag: Graph Greedy
* Time: O(mlgm)
* Space: O(n)
*/

class Solution {
private:
    vector<int> parent;
    
    void init(int n) {
        parent.resize(n + 1);
        
        for(int i = 0; i <= n; ++ i){
            parent[i] = -1;
        }
        
        return ;
    }
    
    int findParent(int u) {
        int newParent = u;
        for(; parent[newParent] >= 0; newParent = parent[newParent]) ;
        
        while(newParent != u) {
            int nextParent = parent[u];
            parent[u] = newParent;
            u = nextParent;
        }
        
        return newParent;
    }
    
    void merge(int u, int v) {
        int parentU = findParent(u), parentV = findParent(v);
        int parentSum = parent[parentU] + parent[parentV];
        if(parent[parentU] <= parent[parentV]) {
            parent[parentU] = parentSum;
            parent[parentV] = parentU;
        } else {
            parent[parentV] = parentSum;
            parent[parentU] = parentV;
        }
        
        return ;
    }
    
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        if(N < 2){
            return -1;
        }
        
        init(N);
        
        sort(connections.begin(), connections.end(), cmp);
    
        int numOfEdges = 0;
        int ans = 0;
        for(vector<int> connection : connections){
            if(findParent(connection[0]) == findParent(connection[1])){
                continue;
            }
            
            ++ numOfEdges;
            ans += connection[2];
            merge(connection[0], connection[1]);
        }
        
        return numOfEdges == N - 1 ? ans : -1;
    }
    
private:
    struct comparator{
        bool operator() (const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        }
    }cmp;
};
