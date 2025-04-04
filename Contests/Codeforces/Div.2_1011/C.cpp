#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define endl '\n'
#define all(x) x.begin(),x.end()

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
const i64 mod=1e9+7;

void Atomatic_AC_machine(){
    //记得开i64
    i64 x,y;
    // cin>>x>>y;
    x=RNG()%64,y=RNG()%64;
    if(x>y) swap(x,y);
    if(x==y){
        cout<<-1<<endl;
        return;
    }
    i64 k=0;
    bool flag=0;
    i64 lsb=0;
    for(int i=0;i<=32;i++){
        // cout<<i<<endl;
        cout<<bitset<34>(x)<<" "<<bitset<34>(y)<<endl;
        i64 bit=(1ll<<i);
        i64 hbit(1ll<<(i+1));
        if(x+y==(x^y)) break;
        if(!!(x&bit)+!!(y&bit)==1){
            lsb=bit;
        }else if(!!(x&bit)+!!(y&bit)==0){
            if(lsb) lsb+=bit;
        }else if((x&bit)&&(y&bit)){
            if(!!(x&hbit)+!!(y&hbit)==1){
                x+=bit;
                y+=bit;
                k+=bit;
                lsb=0;
            }
            else if(!lsb){
                x+=bit;
                y+=bit;
                k+=bit;
            }else{
                x+=lsb;
                y+=lsb;
                k+=lsb;
                lsb=0;
            }
                
        }
    }
    if(x+y!=(x^y)){
        cerr<<"NO"<<endl;
        cout<<x-k<<" "<<y-k<<endl;
        cout<<bitset<34>(x-k)<<" "<<bitset<34>(y-k)<<endl;
        cout<<bitset<34>(x)<<" "<<bitset<34>(y)<<endl;
    }
    cout<<k<<endl;
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