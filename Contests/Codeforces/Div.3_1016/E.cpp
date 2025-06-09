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
int a[N];
int n,k;
bool check(int x){
    vector<int> hav(x+1,0);//mex要到x,必须到x-1
    int cnt=0;
    int pi=0;//当前mex
    for(int i=1;i<=n;i++){
        if(a[i]<=x){
            hav[a[i]]=1;
            while(pi<x&&hav[pi]){
                pi++;
                // db(1)
                // cendl
            }
        }
        if(pi>=x){
            hav.assign(x+1,0);
            pi=0;
            cnt++;
        }
    }
    // db(x<<" "<<cnt<<" "<<pi)
    // cendl
    return cnt>=k;
}
void Atomatic_AC_machine(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=-1,r=n/k+10;//上限mex不会超过n/k
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid)){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<l<<endl;
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