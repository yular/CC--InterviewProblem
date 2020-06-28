/*
*
* Tag: Data Structure Heap
* Time: O(nlgn)
* Space: O(n)
*/

class Solution {
private:
    struct node {
        int id, val;
        bool operator < (const node &a)const{
            return val < a.val;
        }
    };
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        if(k == 0 || n == 0) {
            return 0;
        }
        
        vector<vector<int>> dic(n + 1, vector<int>(2, 0)), g(n + 1, vector<int>(0));
        for(vector<int> dep : dependencies) {
            g[dep[0]].push_back(dep[1]);
            // out deg
            ++ dic[dep[0]][1];
            // in deg
            ++ dic[dep[1]][0];
        }
        
        priority_queue<node> courses;
        for(int i = 1; i <= n; ++ i) {
            if(dic[i][0] > 0) {
                continue;
            }
            
            node nd;
            nd.id = i, nd.val = dic[i][1];
            courses.push(nd);
        }
        
        int ans = 0, cnt = 0;
        vector<int> cache(n);
        while(!courses.empty()) {
            for(int i = 0; i < k && !courses.empty(); ++ i) {
                node cur = courses.top();
                courses.pop();
                
                int u = cur.id;
                for(int v : g[u]) {
                    -- dic[v][0];
                    if(dic[v][0] == 0) {
                        cache[cnt ++] = v;
                    }
                }
            }
            
            for(int i = 0; i < cnt; ++ i) {
                node nd;
                nd.id = cache[i], nd.val = dic[cache[i]][1];
                courses.push(nd);
            }
            
            ++ ans;
            cnt = 0;
        }
        return ans;
    }
};
