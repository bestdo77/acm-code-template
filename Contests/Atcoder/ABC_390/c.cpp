#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
char a[1100][1100];
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    int lm=inf,rm=0,hm=inf,dm=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='#'){
                lm=min(lm,i);
                rm=max(rm,i);
                hm=min(hm,j);
                dm=max(dm,j);
            }
        }
    }
    if(lm==inf){
        cout<<"Yes"<<endl;
    }else{
        bool flag=1;
        for(int i=lm;i<=rm;i++){
            for(int j=hm;j<=dm;j++){
                if(a[i][j]=='.'){
                    flag=0;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}