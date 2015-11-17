/*
*
* Tag: Implementation
* Time: O(n^2)
* Space: O(n^2)
* 模拟题 
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
const int N = 1050;
const double eps = 1e-8;
const double dinf = 1e15;
const int MOD = 100000007;
int n,m;
int mp[N][N];

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        scanf("%d%d",&n,&m);
        int ans = 0;
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                scanf("%d",&mp[i][j]);
                if(!i){
                    ans += mp[i][j];
                    if(!j)
                        ans += mp[i][j];
                    else if(j < m - 1)
                        ans += abs(mp[i][j] - mp[i][j - 1]);
                    if(j == m - 1){
                        ans += mp[i][j];
                        if(j)
                            ans += abs(mp[i][j] - mp[i][j - 1]);
                    }
                }else if(i < n - 1){
                    ans += abs(mp[i][j] - mp[i - 1][j]);
                    if(!j)
                        ans += mp[i][j];
                    else if(j < m - 1)
                        ans += abs(mp[i][j] - mp[i][j - 1]);
                    if(j == m - 1){
                        ans += mp[i][j];
                        if(j)
                            ans += abs(mp[i][j] - mp[i][j - 1]);
                    }
                }else{
                    ans += (mp[i][j] + abs(mp[i][j] - mp[i - 1][j]));
                    if(!j)
                        ans += mp[i][j];
                    else if(j < m - 1)
                        ans += abs(mp[i][j] - mp[i][j - 1]);
                    if(j == m - 1){
                        ans += mp[i][j];
                        if(j)
                            ans += abs(mp[i][j] - mp[i][j - 1]);
                    }
                }
                if(mp[i][j])
                    ++ ans;
            }
            if(n == 1){
                for(int j = 0; j < m; ++ j)
                    ans += mp[i][j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

