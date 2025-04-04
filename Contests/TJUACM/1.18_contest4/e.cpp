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

#define debug(x) cout<<x<<endl;
void print(vector<int> a);
vector<int> generate_data(int n, int range);

void Atomatic_AC_machine(){
    string s;cin>>s;
    s=" "+s;
    int mxr=0,mnr=inf;
    int pb=0;
    int pk=0;
    for(int i=1;i<s.size();i++){
        if(s[i]=='R') {
            mxr=max(mxr,i);
            mnr=min(mnr,i);
        }
        if(s[i]=='K'){
            pk=i;
        }
        if(s[i]=='B'){
            if(!pb) pb=i;
            else if(pb%2==i%2){
                cout<<"No"<<endl;
                return;
            }
            // cout<<i<<" ";
            // cout<<endl;
        }
    }
    // debug(mxr);
    // debug(mnr);
    // debug(pk);
    if(pk<mxr&&pk>mnr){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}   
signed main(){
    
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        //cout << "Case #" << i << ": ";
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
vector<int> generate_data(int n, int range) {
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        data[i] = 1 + RNG() % range; // 生成 1 到 range 之间的随机数
    }
    return data;
}
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}