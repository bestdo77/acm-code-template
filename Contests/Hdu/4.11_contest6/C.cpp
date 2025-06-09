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
    int n;cin>>n;
    vector<i64> a,b,c(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    string s;cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='R'){
            a.push_back(c[i]);
        }else{
            b.push_back(c[i]);
        }
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    i64 ans=0;
    int i=0,j=0;
    while(1){
        if(i<a.size()){
            ans+=a[i];
            i++;
        }else{
            break;
        }
        if(j<b.size()){
            ans+=b[j];
            j++;
        }else{
            break;
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