/*
*
* Tag: Hash
* Time: O(n)
* Space: O(n)
*/
int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int n = A.size();
    vector<bool> vis(n + 1);
    int ans = 0;
    for(int i = 0; i < n; ++ i){
        if(!vis[A[i]])
            ans = i;
        vis[A[i]] = 1;
    }
    return ans;
}
