#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=998244353;
#define debug(x) cout<<x<<endl;
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}
int a[N1][N1];
int a1[N1][N1];
int b[N1][N1];
int n;
void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a1[i][j];
        }
        cout<<endl;
    }
}
bool check(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // cout<<a1[i][j]<<" "<<b[i][j]<<endl;
            if(a1[i][j]==1&&b[i][j]!=1){
                return false;
            }
        }
    }
    return true;
}
void copy(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=a1[i][j];
        }
    }
}
void rotate(){
    copy();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a1[i][j]=a[n+1-j][i];
        }
    }
    // cout<<endl;
    // print();
    // cout<<endl;
}
void Atomatic_AC_machine(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            a1[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<4;i++){
        if(check()){
            cout<<"Yes"<<endl;
            return;
        }
        rotate();
    }
    cout<<"No"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}