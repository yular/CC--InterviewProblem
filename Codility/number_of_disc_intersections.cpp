/*
*
* Tag: Data Structure
* Time: O(nlgn)
* Space: O(n)
*/
#include <algorithm>
#include <set>
#include <unordered_map>
const int BND = 10000000;
unordered_map<long long, int> dict;
set<long long> st;
vector<int> bintree;

int lowbit(int x){
    return x&-x;
}

int sumup(int bnd){
    int res = 0;
    for (int i = bnd; i > 0; i -= lowbit(i)) {
        res += bintree[i];
    }
    return res;
}

void updateval(int sta, int bnd){
    for (int i = sta; i <= bnd; i += lowbit(i)) {
        ++ bintree[i];
    }
}

bool cmp(const pair<long long, long long> &a, const pair<long long, long long> &b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solution(vector<int> &A){
    int res = 0, n = (int)A.size();
    dict.clear();
    st.clear();
    for (int i = 0; i < A.size(); ++ i) {
        long long l = (long long)i - A[i], r = (long long)i + A[i];
        st.insert(l);
        st.insert(r);
    }
    int cnt = 1;
    for (set<long long>::iterator it = st.begin(); it != st.end(); ++ it, ++ cnt) {
        dict[*it] = cnt;
    }
    vector<pair<long long,long long>> circle;
    circle.resize(A.size());
    for (int i = 0; i < A.size(); ++ i) {
        long long l = (long long)i - A[i], r = (long long)i + A[i];
        circle[i] = make_pair(dict[l],dict[r]);
    }
    sort(circle.begin(), circle.end(), cmp);
    bintree.resize(cnt + 10);
    for (int i = 0; i < A.size(); ++ i) {
        res += sumup(circle[i].second) - sumup(circle[i].first - 1);
        if(res > BND)
            break;
        updateval(circle[i].second, cnt);
    }
    return res > BND?-1:res;
}
