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
    map<pii,int> vis;
    int n;cin>>n;
    vector<int> ocr1(n+1,0),ocr2(n+1,0);
    vector<int> a(2*n+1,0);
    for(int i=1;i<=2*n;i++){
        int x;cin>>x;
        a[i]=x;
        if(!ocr1[x]){
            ocr1[x]=i;
        }else ocr2[x]=i;
    }   
    for(int i=1;i<2*n;i++){
        if(a[i]==a[i+1]) continue;
        if(ocr2[a[i]]==i||ocr2[a[i+1]]==i+1) continue;
        if(abs(ocr2[a[i]]-ocr2[a[i+1]])<=1&&abs(ocr1[a[i]]-ocr2[a[i]])!=1&&abs(ocr1[a[i+1]]-ocr2[a[i+1]])!=1){
            int u=a[i],v=a[i+1];
            vis[{u,v}]=1;
        }
    }
    cout<<vis.size()<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}