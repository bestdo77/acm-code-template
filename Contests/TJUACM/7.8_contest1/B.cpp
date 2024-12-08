#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000],p=0;
const int MAXN=1e3+10;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for(int i=100;i<=919;i++){
        int x3=i/100;
        int x2=i%100/10;
        int x1=i%10;
        if(x3*x2==x1) a[++p]=i;
    }
    cout<<*lower_bound(a+1,a+p+1,n)<<endl;
    return 0;
}