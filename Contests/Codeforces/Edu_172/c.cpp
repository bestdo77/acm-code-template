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
int a[N];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    s=" "+s;
    a[n+1]=0;
    for(int i=n;i>=1;i--){
        if(s[i]=='0'){
            a[i]=a[i+1]-1;
        }else{
            a[i]=a[i+1]+1;
        }
    }
    sort(a+2,a+1+n,greater<int>());
    int ans=0;
    for(int i=2;i<=n;i++){
        ans+=a[i];
        if(ans>=k){
            cout<<i<<endl;
            return;
        }
    }
    if(ans>=k){
        cout<<n<<endl;
        return;
    }else{
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