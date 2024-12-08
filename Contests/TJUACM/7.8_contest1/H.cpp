#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000];
const int MAXN=1e3+10;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double n,d,k;
    scanf("%lf %lf %lf",&n,&d,&k);
    double dis=0;
    for(int i=1;i<=10000;i++){
        a[i]=i*n*4;
    }
    double p=0;
    for(int i=1;i<=k;i++){
        dis+=d;
        while(dis>4*n){
            dis-=*lower_bound(a+1,a+10000+1,dis);
        }
        if(dis<=n) printf("%.5lf %.5lf\n",dis,p);
        else if(dis<=2*n) printf("%.5lf %.5lf\n",n,dis-n);
        else if(dis<=3*n) printf("%.5lf %.5lf\n",3*n-dis,n);
        else printf("%.5lf %.5lf\n",p,4*n-dis);
    }
    return 0;
}