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
int a[N];
int b[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        cin>>b[j];
    }
    sort(b+1,b+1+n,greater<int>());
    vector<int> queue;
    int cru=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==b[i]){
            cru=b[i];
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=cru&&b[i]!=cru){
            queue.push_back(i);
        }
    }
    if(cnt>queue.size()){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++){
        if(a[i]==b[i]){
            int x=queue.back();
            queue.pop_back();
            swap(b[i],b[x]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}