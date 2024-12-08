#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int INF =2147483647;
const int MAXN=1e5+3;
int n,t,H[MAXN],F[MAXN];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>H[i];
    F[0]=INF;
   for(int i=1;i<=n;i++){
        int x=upper_bound(F+1,F+1+t,H[i])-F;
        if(x>t) t=x; 
        F[x]=H[i];
    }
    printf("%d\n",t);
    return 0;
}