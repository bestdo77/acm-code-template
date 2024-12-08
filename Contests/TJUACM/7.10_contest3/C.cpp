#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
int a[5100000],b[5100000];
const int MAXN=1e3+10;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    int t;cin>>t;
    while(t--){
        bool flag=1;
        int n;cin>>n;
        int sum=0,tmp=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum!=0){
            cout<<"No"<<endl;
            continue;
        }
        tmp=-a[n];
        for(int i=n-1;i>=1;i--){
            if(a[i]-tmp>=0) flag=0;
            tmp=-(a[i]-tmp);
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}