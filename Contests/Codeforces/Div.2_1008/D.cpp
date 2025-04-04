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
pii play[2][N];//add 0,mul 1
void Atomatic_AC_machine(){
    int n;cin>>n;
    int l=1,r=1;
    for(int i=1;i<=n;i++){
        char op;int x;
        cin>>op>>x;
        if(op=='+'){
            play[0][i]={x,0};
        }else{
            play[0][i]={x,1};
        } 
        cin>>op>>x;
        if(op=='+'){
            play[1][i]={x,0};
        }else{
            play[1][i]={x,1};
        } 
    }
    int re=0;
    for(int i=1;i<=n;i++){
        auto [x0,op0]=play[0][i];
        auto [x1,op1]=play[1][i];
        int tmp=re;
        if(op0==op1&&op0==1){
            if(x0>x1){
                re=(re+l)*(x0-1)+r*(x1-1);
                l+=tmp;
            }else if(x0==x1){
                re+=(l+r+re)*(x0-1);
            }else{
                re=(re+r)*(x1-1)+l*(x0-1);
                r+=tmp;
            }
        }else{
            if(op0==1){
                re=(re+l)*(x0-1)+x1;
                l+=tmp;
            }else if(op1==1){
                re=(re+r)*(x1-1)+x0;
                r+=tmp;
            }else{
                re+=x0+x1;
            }
        }
        db(l<<" "<<r<<" "<<re)
        cendl
    }
    cout<<l+r+re<<endl;
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