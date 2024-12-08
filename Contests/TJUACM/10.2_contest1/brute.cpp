#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int a[1000][1000];
int ff[10000];
void Atomatic_AC_machine(){
    a[0][1]=1;
    for (int i=1;i<=100;i++){
        for (int j=1;j<=100;j++){
            a[i][j]=a[i-1][j]+a[i-1][j-1]+a[i-1][j+1];
        }
    }
    int test;
    cin >>test;
    while (test){
        for (int i=1;i<=32;i++){
            if (a[30][i]<=test){
                test-=a[30][i];
                cout <<a[30][i]<<" ";
                break;
            }
        }
    }
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