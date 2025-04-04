#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
int sum[N];
void Atomatic_AC_machine(){
    int k;cin>>k;
    int p=0;
    int x=1,h=1;
    for(int i=2;i<=500;i++){
        if(k<sum[i]){
            p=i-1;
            break;
        }
    }
    db(p)
    cendl
    vector<pii> ans;
    for(int i=p;i>=2;i--){
        db(k)
        cendl
        while(k>=sum[i]){
            k-=sum[i];
            for(int j=1;j<=i;j++){
                ans.push_back({x,h});
                x++;
            }
            h++;
        }
    }
    // while(ans.size()<n){
    //     ans.push_back(x,h);
    //     x++,h++;
    // }
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans){
        cout<<x<<" "<<y<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    for(int i=2;i<=500;i++){
        sum[i]=i*(i-1)/2;
    }
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}