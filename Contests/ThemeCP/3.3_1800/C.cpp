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
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> h,l;
    for(int i=1;i<=n;i++){
        if(a[i]>=0){
            h.push_back(a[i]);
        }else{
            l.push_back(a[i]);
        }
    }
    int lim=*max_element(a+1,a+1+n)-*min_element(a+1,a+1+n);
    sort(h.begin(),h.end(),greater<int>());
    sort(l.begin(),l.end());
    int p1=0,p2=0;
    vector<int> ans(n+1,0);
    int pre=0;
    for(int i=1;i<=n;i++){
        if(p2!=l.size()&&(p1==h.size()||pre+h[p1]>=lim)){
            ans[i]=l[p2];
            pre+=l[p2];
            p2++;
            if(abs(pre)>=lim){
                cout<<"NO"<<endl;
                return;
            }
        }else if(p1!=h.size()){
            ans[i]=h[p1];
            pre+=h[p1];
            p1++;
            if(pre>=lim){
                cout<<"NO"<<endl;
                return;
            }
        }else{
            cout<<"NO"<<endl;
            return;
        }
        db(ans[i])
    }
    cendl
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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