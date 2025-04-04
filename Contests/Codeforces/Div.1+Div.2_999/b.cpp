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
// map<int,int> mp;
int a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int pos=0;
    for(int i=n;i>=0;i--){
        if(a[i-1]==a[i]){
            pos=i-1;
            break;
        }
    }
    vector<int> check;
    for(int i=1;i<=n;i++){
        if(!(i==pos||i==pos+1)){
            check.emplace_back(a[i]);
        }
    }
    if(pos==0){
        cout<<-1<<endl;
    }else{
        for(int i=1;i<check.size();i++){
            if(check[i]-check[i-1]<a[pos]*2){
                cout<<check[i]<<" "<<check[i-1]<<" "<<a[pos]<<" "<<a[pos]<<endl;
                return;
            }
        }
        cout<<-1<<endl;
    }
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}