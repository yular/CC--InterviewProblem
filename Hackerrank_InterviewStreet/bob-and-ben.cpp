/*
*
*
*
*/
#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int i,j,k,l,t,n,m,ca;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main(){
    ca=read();
    while (ca--){
        n=read();
        t=0;
        fo(i,1,n){
            j=read();k=read();
            if (j==1) t^=1;
            else if (j>2){
                if (j%2==1) t^=1;
                else t^=2;
            }
        }
        if (t) printf("BOB\n");else printf("BEN\n");
    }
}
