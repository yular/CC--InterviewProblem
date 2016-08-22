/*
*
* Tag: Graph Theory
* Time: O(nlgn)
* Space: O(n)
*/
#include <climits>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 306010;
const int M = 100100;
const long long MOD = 1000000007;
const double eps = 1e-10;
const double pi = acos(-1.0);
struct node{
    int u,v,w;
    int nxt;
}e[N];
int head[M], num, n, s, t, dist[M];
//bool vis[M];
unordered_map<int, int> dict;

void init(){
    num = 0;
    for (int i = 0; i <= n; ++ i){
        head[i] = -1;
        dist[i] = INT_MAX;
    }
}

void addedge(int u, int v, int w){
    e[num].u = u;
    e[num].v = v;
    e[num].w = w;
    e[num].nxt = head[u];
    head[u] = num ++;
}

struct cmp{
    bool operator () (const int &a, const int &b){
        return dist[a] > dist[b];
    }
};

priority_queue<int, vector<int>, cmp> pq;
void dijk(){
    dist[s] = 0;
    pq.push(s);
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        for (int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v, w = e[i].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(v);
            }
        }
    }
}

int solution(vector<int> &A){
    int res = 0;
    if (A.size() == 0) {
        return res;
    }
    n = 0;
    dict.clear();
    for (int i = 0; i < A.size(); ++ i) {
        if (dict.find(A[i]) == dict.end())
            dict[A[i]] = n ++;
        if (i == 0) {
            s = dict[A[i]];
        }else if(i == A.size() - 1){
            t = dict[A[i]];
        }
    }

    init();
    for (int i = 0; i < A.size() - 1; ++ i) {
        addedge(dict[A[i]], dict[A[i + 1]], 1);
        addedge(dict[A[i + 1]], dict[A[i]], 1);
    }
    if (s == t) {
        return 1;
    }
    dijk();
    res = dist[t] + 1;
    return res;
}
