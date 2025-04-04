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
i64 hav[N];
i64 buy[N];
int n;
bool check(i64 x){
    i64 mx=0;//前缀最大值
    i64 prem=0;//剩的钱
    i64 precnt=0;//剩的币
    for(int i=1;i<=n;i++){
        //买币
        if(precnt<x){
            i64 cost=(x-precnt)/mx+!!((x-precnt)%mx);
            precnt=precnt+cost*mx-x;//剩的币
            prem+=hav[i]-cost;
            if(prem<0) return 0;
        }else{
            precnt-=x;
            prem+=hav[i];
        }
    }
    return 1;
}
void Atomatic_AC_machine(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>buy[i];
    }
    for(int i=1;i<=n;i++){
        cin>>hav[i];
    }
    i64 l=0,r=1e15;
    while(l+1<r){
        i64 mid=(l+r)>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}