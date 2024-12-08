#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int stc[N];
int sum=0;
int res=inf;
int vis[N];
bool dfs(int len,int cntt,int pos,int des,int n){//目前拼了多长，拼了多少个，遍历最左端位置，一根有多长
    // cout<<len<<" "<<cntt<<" "<<pos<<" "<<des<<endl;
    // if(pos>=n) return -inf;
    if(cntt>=sum/des){
        return true;
    }
    if(len==des){
        return dfs(0,cntt+1,1,des,n);
    }
    int lst=0;
    for(int i=pos;i<=n;i++){
        if(!vis[i]&&len+stc[i]<=des&&lst!=stc[i]){
            lst=stc[i];
            vis[i]=1;
            if(dfs(len+stc[i],cntt,pos+1,des,n)) return true;
            vis[i]=0;
            if(len==0||stc[i]+len==res) return false;
        }
    }
    // return false;
}
void Atomatic_AC_machine(int n){
    res=inf;
    sum=0;
    for(int i=1;i<=n;i++){
        cin>>stc[i];
        sum+=stc[i];
    }
    sort(stc+1,stc+1+n);
    reverse(stc+1,stc+1+n);
    // for(int i=1;i<=n;i++){
    //     cout<<stc[i]<<" ";
    // }
    // cout<<endl;
    vector<int> fac;
    for(int i=stc[1];i<=sum;i++){
        if(sum%i==0){
            fac.push_back(i);
            // cout<<i<<endl;
        } 
    }
    for(int i=0;i<fac.size();i++){
        // cout<<it<<endl;
        for(int i=1;i<=n;i++) vis[i]=0;
        if(dfs(0,0,1,fac[i],n)){
            cout<<fac[i]<<endl;
            return;
        }
    }
}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++) vis[i]=0;
        if(n==0) return 0;
        Atomatic_AC_machine(n);
    }
    // return 0;
}