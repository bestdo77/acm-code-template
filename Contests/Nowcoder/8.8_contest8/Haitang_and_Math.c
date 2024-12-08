#include <stdio.h>
#include <math.h>
#define ll long long
#define int long long
// #define pii pair <int,int>
#define ld long double
#define endl "\n"
// #pragma GCC optimize(3,"Ofast","inline")
const int N=200050;
inline int S(int m){
    int sum=0;
    while (m){
        sum+=m%10;
        m= (m >> 3) + (m >> 1);
    }
    return sum;
}

int St[2000050];
signed main (){
    int t;
    scanf("%ld",&t);
    for (register int i=0;i<=2000025;i++){
        St[i]=S(i);
    }
    while (t--){
        ll n;
        scanf("%ld",&t);
        int sq=sqrt(n);
        int ans=0;
        for (register int i=1;i<=sq*2;i++){
            if((n%i)==St[i]){
                ans++;
            }
        }
        for(register int i = sq*2+1,j;i <=n;i = j + 1){
        j = n / (n / i);
        int ttt=n%j;
        int dev=n/i;
        for(register int k=j;k>=i && ttt<=108;--k,ttt+=dev){
             if((n%k)==S(k)){
                ans++;
            }
        }
    }
    printf("%ld\n",ans);    
    }
}