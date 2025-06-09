#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;

void Atomatic_AC_machine(){
    int k,a,b,c;
    cin>>k>>a>>b>>c;
    int ans=inf;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int p=0;p<2;p++){
                int kk=k;
                if(i==1) kk-=a;
                if(j==1) kk-=b;
                if(p==1) kk-=c;
                if(kk<0) continue;
                ans=min(kk,ans);
            }
        }

    }
    cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}