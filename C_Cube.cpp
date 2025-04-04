#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
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
const int mod=1e9+7;
i64 a[100][100][100];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            for(int z=0;z<n;z++){
                cin>>a[x][y][z];
            }
        }
    }
    vector<vector<i64>> dp((1ll<<n),vector<i64>(1ll<<n,inf));
    dp[0][0]=0;
    for(int x=0;x<n;x++){    
        for(int yy=0;yy<(1ll<<n);yy++){
            for(int zz=0;zz<(1ll<<n);zz++){
                if(__builtin_popcount(yy)==x&&__builtin_popcount(zz)==x){
                    for(int y=0;y<n;y++){
                        for(int z=0;z<n;z++){
                            if(yy&(1ll<<y)||(zz&(1ll<<z))) continue;
                            dp[yy^(1ll<<y)][zz^(1ll<<z)]=min(dp[yy^(1ll<<y)][zz^(1ll<<z)],dp[yy][zz]+a[x][y][z]);       
                        }
                    }
                }
            }
        }
    }
    cout<<dp[(1ll<<n)-1][(1ll<<n)-1]<<endl;
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
/*
Case 1:
0 4557430888798830399 4557430888798830399 4557430888798830399 4557430888798830399 4557430888798830399 4557430888798830399 4557430888798830399 
4557430888798830399 1 2 4557430888798830399 3 4557430888798830399 4557430888798830399 4557430888798830399 
4557430888798830399 4 5 4557430888798830399 6 4557430888798830399 4557430888798830399 4557430888798830399 
4557430888798830399 4557430888798830399 4557430888798830399 3 4557430888798830399 3 4 4557430888798830399 
4557430888798830399 7 8 4557430888798830399 9 4557430888798830399 4557430888798830399 4557430888798830399 
4557430888798830399 4557430888798830399 4557430888798830399 4 4557430888798830399 4 5 4557430888798830399 
4557430888798830399 4557430888798830399 4557430888798830399 7 4557430888798830399 7 8 4557430888798830399 
4557430888798830399 4557430888798830399 4557430888798830399 4557430888798830399 4557430888798830399 4557430888798830399 4557430888798830399 5 
*/