#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
string a[N1];
string b[N1];
string a1[N1];
string a2[N1];
int n,m;
void swapcol(int s){
    for(int i=0;i<n;i++){
        a1[i]=b[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a1[i][j]=b[i][(j+s)%m];
        }
    }
}
void swapline(int t){
    for(int i=0;i<n;i++){
        a2[i]=a1[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a2[i][j]=a1[(i+t)%n][j];
        }
    }
}
bool check(){
    bool flag=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a2[i][j]!=a[i][j]){
                flag=0;
                break;
            }
        }
    }
    return flag;
}
void Atomatic_AC_machine(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int t=0;t<n;t++){
        for(int s=0;s<m;s++){
            swapcol(s);
            swapline(t);
            if(check()){
                cout<<"Yes"<<endl;
                return;
            }
        }
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