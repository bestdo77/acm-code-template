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
bool check(int x){
    return (int)sqrt(x)*(int)sqrt(x)==x;
}
int a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<int> ans;
    if(check(n*(n+1)/2)){
        cout<<"-1"<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(check(i*(i+1)/2)){
            ans.push_back(i+1);
            ans.push_back(i);
            i++;
        }else{
            ans.push_back(i);
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
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