#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
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
int dis(int x1,int y1,int x2,int y2){
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
void Atomatic_AC_machine(){
    int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    if(dis(x2,y2,x1+2,y1+1)==5||dis(x2,y2,x1+2,y1-1)==5||dis(x2,y2,x1-2,y1+1)==5||dis(x2,y2,x1-2,y1-1)==5||dis(x2,y2,x1+1,y1+2)==5
    ||dis(x2,y2,x1+1,y1-2)==5||dis(x2,y2,x1-1,y1+2)==5||dis(x2,y2,x1-1,y1-2)==5){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
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