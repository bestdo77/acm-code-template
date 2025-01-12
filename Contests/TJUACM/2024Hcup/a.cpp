#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[N][N],b[N][N],c[N][N],line[N],ansa[N],ansb[N],ansc[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        line[i]=i;
    }
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=n;j++){
             tmp+=line[j]*a[j][i];
        }
        ansa[i]=tmp;
    }
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=n;j++){
             tmp+=line[j]*b[j][i];
        }
        ansb[i]=tmp;
    }
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=n;j++){
             tmp+=line[j]*c[j][i];
        }
        ansc[i]=tmp;
    }
    bool flag=1;
    for(int i=1;i<=n;i++){
        if(ansa[i]+ansb[i]!=ansc[i]){
            flag=0;
            break;
        }
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}