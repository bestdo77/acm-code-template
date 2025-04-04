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
int add[11];
bool check(int x){
    while(x){
        if(x%10==7){
            return 1;
        }
        x/=10;
    }
    return 0;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    int mn=inf;
    for(int i=1;i<=9;i++){
        for(int j=0;j<=9;j++){
            if(check(n+add[i]*j)){
                mn=min(mn,j);
            }
        }
    }
    cout<<mn<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    int cnt=0;
    for(int i=0;i<=10;i++){
        add[i]=cnt;
        cnt*=10;
        cnt+=9;
    }
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}