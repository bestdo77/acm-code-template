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
// int px,py;
int dx[4]={-1,0,1,0};//NESW
int dy[4]={0,-1,0,1};
map<pii,int> vis;
void Atomatic_AC_machine(){
    int n,r,c;cin>>n>>r>>c;
    string s;cin>>s;
    string ans;
    int r1=0,c1=0;
    vis[{0,0}]=1;
    for(auto ch:s){
        if(ch=='S'){    
            r+=dx[0];
            c+=dy[0];
            r1+=dx[0];
            c1+=dy[0];
        }else if(ch=='E'){
            r+=dx[1];
            c+=dy[1];
            r1+=dx[1];
            c1+=dy[1];
        }else if(ch=='N'){
            r+=dx[2];
            c+=dy[2];
            r1+=dx[2];
            c1+=dy[2];
        }else if(ch=='W'){
            r+=dx[3];
            c+=dy[3];
            r1+=dx[3];
            c1+=dy[3];
        }
        vis[{r1,c1}]=1;
        if(vis[{r,c}]) ans.push_back('1');
        else ans.push_back('0');
        // cout<< r1<<" "<<c1<<" "<<r<<" "<<c<<endl;
    } 
    cout<<ans<<endl;

}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}