#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;

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

struct node{
    i64 x,y,d,cnt;
    bool operator<(const node &b)const{
        if(d==b.d){
            return (x==b.x)?(y<b.y):(x<b.x); 
        }else return d<b.d;
    }
};
void Atomatic_AC_machine(){
    set<node> st,st1;
    int n;   //n个客人，最多n张桌子
    cin>>n;
    vector<int> vis(4*n+10,0);
    i64 x=0,y=0;
    int cnt=0;
    for(int x=0;x<=2*sqrt(n);x++){
        for(int y=0;y<=2*sqrt(n);y++){
            st.insert(node{3*x+1,3*y+1,3*x+3*y+2,0});
        }
    }
    vector<pii> ans;
    for(int i=1;i<=n;i++){
        int c=0;cin>>c;
        if(c==0){
            auto [x,y,d,cnt]=*st.begin();
            st.erase(*st.begin());
            ans.push_back({x,y});
            st1.insert({x,y+1,d+1,cnt+1});
        }else{
            auto P1=*st.begin();
            auto P2=node{inf,inf,inf,inf};
            if(st1.size()) P2=*st1.begin();
            if(P1<P2){
                st.erase(st.begin());
                auto [x,y,d,cnt]=P1;
                ans.push_back({x,y});
                st1.insert({x,y+1,d+1,cnt+1});
            }else{
                auto [x,y,d,cnt]=P2;
                ans.push_back({x,y});
                st1.erase(st1.begin());
                if(cnt==1){
                    st1.insert({x+1,y-1,d,cnt+1});
                }else if(cnt==2){
                    st1.insert({x,y+1,d+3,cnt+1});
                }
            }
        }
    }
    for(auto [x,y]:ans){
        cout<<x<<" "<<y<<endl;
    }
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