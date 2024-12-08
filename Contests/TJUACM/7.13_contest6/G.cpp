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
        int x,y;cin>>x>>y;
        if(abs(x-y)<=1) cout<<x+y<<endl;
        else{
            cout<<(max(x,y)-min(x,y)-1)*2+2*(min(x,y))+1<<endl;
        }
    }
    return 0;
}