#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
#define all(x) x.begin(),x.end()
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
const int N1=2e3+10;
const int mod=1e9+7;
char G[N1][N1];
int cntH[26][N1];
int cntW[26][N1];
int cost[26];
void Atomatic_AC_machine(){
    int H,W; cin>>H>>W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            char x;cin>>x;
            int ch=x-'a';
            G[i][j]=ch;
            cntH[ch][i]++;
            cntW[ch][j]++;
        }
    }
    int cnt=H*W;
    int h=H,w=W;
    for(int _=1;_<=(H+W);_++){    
        vector<pii> delx,dely;
        for(int i=0;i<26;i++){
            for(int j=1;j<=H;j++){
                if(cntH[i][j]==w&&w>=2){
                    delx.push_back({i,j});
                }
            }
        }
        for(int i=0;i<26;i++){
            for(int j=1;j<=W;j++){
                if(cntW[i][j]==h&&h>=2){
                    dely.push_back({i,j});
                }
            }    
        }
        for(auto [x,y]:delx){
            for(int j=1;j<=W;j++){
                cntW[x][j]--;
            }
            cntH[x][y]=0;
            h--;
        }
        for(auto [x,y]:dely){
            for(int j=1;j<=H;j++){
                cntH[x][j]--;
            }
            cntW[x][y]=0;
            w--;
        }
    }
    cout<<h*w<<endl;
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