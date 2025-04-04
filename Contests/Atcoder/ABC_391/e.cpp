#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=2e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
string s;
// Fenwick tr(N);
int c21(int l,int r){
    if(r==l){
        if(s[r]=='1') return 0;
        else return 1;
    }
    // db(1)
    // cendl
    int len=(r-l+1)/3;
    vector<int> cst(3);
    cst[0]=c21(l,l+len-1);
    cst[1]=c21(l+len,l+2*len-1);
    cst[2]=c21(l+2*len,r);
    sort(cst.begin(),cst.end());
    // db(l<<" "<<r<<" "<<cst[0]+cst[1])
    // cendl
    return cst[0]+cst[1];
}
int c20(int l,int r){
    if(r==l){
        if(s[r]=='1') return 1;
        else return 0;
    }
    int len=(r-l+1)/3;
    vector<int> cst(3);
    cst[0]=c20(l,l+len-1);
    cst[1]=c20(l+len,l+2*len-1);
    cst[2]=c20(l+2*len,r);
    sort(cst.begin(),cst.end());
    // db(l<<" "<<r<<" "<<cst[0]+cst[1])
    // cendl
    return cst[0]+cst[1];
}
int ans(int l,int r){
    if(r==l){
        if(s[r]=='1') return 1;
        else return 0;
    }
    int len=(r-l+1)/3;
    int ans1=0;
    // vector<int> cst(3);
    ans1+=ans(l,l+len-1);
    ans1+=ans(l+len,l+2*len-1);
    ans1+=ans(l+2*len,r);
    return ans1>=2;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    int len=pow(3,n);
    cin>>s;
    s=" "+s;
    int op=ans(1,len);
    // db(op)
    // cendl
    if(op==1){
        cout<<c20(1,len)<<endl;
    }else{
        cout<<c21(1,len)<<endl;
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