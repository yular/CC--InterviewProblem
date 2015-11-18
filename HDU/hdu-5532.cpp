/*
*
* Tag: DP (LIS)
* Time: O(nlgn)
* Space: O(n)
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<climits>
#include<stdlib.h>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<bitset>
#include<set>
#include<cmath>
#include<list>
#include<sstream>
#include<time.h>
using namespace std;
const int M = 100030;
const int N = 100500;
const double eps = 1e-8;
const double dinf = 1e15;
const int MOD = 100000007;
int n;
int a[N], b[N], c[N], top;

void bsearch(int val){
    int l = 0, r = top - 1;
    if(val >= c[top - 1]){
        c[top ++] = val;
        return ;
    }
    while(l <= r){
        int mid = (l + r)>>1;
        if(c[mid] > val)
            r = mid - 1;
        else
            l = mid + 1;
    }
    c[l] = val;
}

bool LIS(const int d[]){
    top = 0;
    for(int i = 0; i < n; ++ i){
        if(!i)
            c[top ++] = d[i];
        else{
            bsearch(d[i]);
        }
    }
    return top >= n - 1;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d",&n);
        for(int i = 0; i < n; ++ i){
            scanf("%d",&a[i]);
            b[n - i - 1] = a[i];
        }
        if(LIS(a) || LIS(b))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
