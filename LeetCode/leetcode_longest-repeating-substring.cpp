/*
*
* Tag: Suffix Array
* Time: O(nlgn)
* Space: O(n)
*/
class Solution {
private:
    int wa[100005], wb[100005], wc[100005], wv[100005];
    int ranks[100005], lcp[100005];
    int r[100005], sa[100005];
public:
    int longestRepeatingSubstring(string S) {
        if(S.size() < 2) {
            return 0;
        }
        
        memset(r, 0, sizeof(r));
        memset(ranks, 0, sizeof(ranks));
        
        int n = S.length(), k;
        for (int i = 0; i < n; ++ i) {
            r[i] = (int)S[i];
        }
        da(r, sa, n + 1, 256);
        calLCP(r, sa, n);
      
        int maxLen = 0;
        for (int i = 0; i <= n; i++) {
            if (lcp[i] > maxLen) {
                maxLen = lcp[i];
            }
        }
        return maxLen;
    }
private:
    void da(int *r, int *sa, int n, int m){
        int *x = wa, *y = wb, *t;
        int j, p;
        for (int i = 0; i < m;  ++ i) {
            wc[i] = 0;
        }
        for (int i = 0; i < n; ++ i) {
            ++ wc[x[i] = r[i]];
        }
        for (int i = 1; i < m; ++ i) {
            wc[i] += wc[i - 1];
        }
        for (int i = n - 1; i >= 0; -- i) {
            sa[-- wc[x[i]]] = i;
        }
        for (j = 1, p = 1; p < n; j *= 2, m = p) {
            int i;
            for (p = 0, i = n - j; i < n; ++ i) {
                y[p ++] = i;
            }
            for (i = 0; i < n; ++ i) {
                if (sa[i] >= j) {
                    y[p ++] = sa[i] - j;
                }
            }
            for (i = 0; i < n; ++ i) {
                wv[i] = x[y[i]];
            }
            for (i = 0; i < m; ++ i) {
                wc[i] = 0;
            }
            for (i = 0; i < n; ++ i) {
                ++ wc[wv[i]];
            }
            for (i = 1; i < m; ++ i) {
                wc[i] += wc[i - 1];
            }
            for (i = n - 1; i >= 0; -- i) {
                sa[--wc[wv[i]]] = y[i];
            }
            for (t = x, x= y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; ++ i) {
                x[sa[i]] = cmp(y, sa[i - 1], sa[i], j)?p - 1 : p ++;
            }
        }
        return ;
    }
    
    int cmp(int *r, int a, int b, int l){
        return r[a] == r[b] && r[a + l] == r[b + l];
    }


    void calLCP(int *r, int *sa, int n){
        int i, j, k = 0;
        for (i = 1; i <= n; ++ i) {
            ranks[sa[i]] = i;
        }
        for (i = 0; i < n; lcp[ranks[i ++] - 1] = k) {
            for (k?k--:0, j = sa[ranks[i] - 1]; r[i + k] == r[j + k]; ++ k) ;            
        }
        return ;
    }
};
