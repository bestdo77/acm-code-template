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
    vector<int> vis(n+1);
    string s,t;cin>>s>>t;
    s=" "+s+" ";
    t=" "+t+" ";
    int cntO=0,cntE=0;
    for(int i=1;i<=n;i++){
        if(t[i]=='0'){
            if(i%2) cntO++;
            else cntE++;
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            if(i%2==0) cntO--;
            else cntE--;
        }
        if(cntO<0||cntE<0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;

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