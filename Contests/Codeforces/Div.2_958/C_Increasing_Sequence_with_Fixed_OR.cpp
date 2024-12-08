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
        int n;cin>>n;
        int p=log2(n)+1;
        if(1<<(int)log2(n)==n){
            cout<<1<<endl;
            cout<<n<<endl;
            continue;
        }
        int cnt=0;
        for(int i=0;i<p;i++){
            int k=1LL<<i;
            if(k&n) cnt++;
        }
        cout<<cnt+1<<endl;
        for(int i=p;i>=0;i--){
            int k=1LL<<i;
            if(k&n) cout<<(n-k)<<" ";
        }
        cout<<n<<" ";
        cout<<endl;

    }
    return 0;
}