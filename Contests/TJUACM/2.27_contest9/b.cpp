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
vector<int> con(int x,int n){
    vector<int> res;
    while(x){
        res.push_back(x%4);
        x/=4;
    }
    while(res.size()<n){
        res.push_back(0);
    }
    return res;
}
int arr[N];
void Atomatic_AC_machine(){

    int n,a,b,c;cin>>n>>a>>b>>c;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cost=inf;
    for(int i=0;i<(int)pow(4,n);i++){
        vector<int> p=con(i,n);
        // pa(p);
        int tmpa=0,tmpb=0,tmpc=0;
        int tmpcost=0;
        for(int j=0;j<n;j++){
            if(p[j]==0){
                if(tmpa) tmpcost+=10;
                tmpa+=arr[j];
            }else if(p[j]==1){
                if(tmpb) tmpcost+=10;
                tmpb+=arr[j];
            }else if(p[j]==2){
                if(tmpc) tmpcost+=10;
                tmpc+=arr[j];
            }
        }
        if(tmpa==0||tmpb==0||tmpc==0){
            continue;
        }
        tmpcost+=abs(a-tmpa)+abs(b-tmpb)+abs(c-tmpc);
        cost=min(cost,tmpcost);
    }
    cout<<cost<<endl;
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