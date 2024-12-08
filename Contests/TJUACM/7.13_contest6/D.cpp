#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int x=0,y=0;
        while(x*x*k*k+y*y*k*k<=n*n){
            if(x==y) x++;
            else y++;
        }
        if(x+y%2) cout<<"Utkarsh"<<endl;
        else cout<<"Ashish"<<endl;

    }
    return 0;
}