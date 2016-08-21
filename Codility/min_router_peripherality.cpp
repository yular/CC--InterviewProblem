/*
*
* Tag: Graph Theory
* Time: O(n)
* Space: O(n)
*/
int solution(vector<int> &T) {
    // write your code in C++11 (g++ 4.8.2)
    int n = (int)T.size(), m = 0;
    int u, v;
    if(n <= 2)
        return 0;
    vector<int> d(n, 0), o(n, -1), s(n, 1);
    for(int i = 0; i < n; ++ i){
        if(T[i] != i)
            ++ d[T[i]];
    }
    for(int i = 0; i < n; ++ i){
        if(d[i] == 0){
            o[m] = i;
            ++ m;
        }
    }
    for(int i = 0; i < n - 1; ++ i){
        u = o[i];
        v = T[u];
        -- d[v];
        if(!d[v]){
            o[m] = v;
            ++ m;
        }
    }
    for(int i = 0; i < n; ++ i){
        u = o[i];
        v = T[u];
        s[v] += s[u];
        if(2*s[v] > n)
            return v;
        if(2*s[v] == n)
            return min(v, T[v]);
    }
    return 0;
}
