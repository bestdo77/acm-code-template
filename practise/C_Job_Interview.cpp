#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
pii a[N];
vector<int> G[N];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n+m+1;i++) cin>>a[i].first;
    for(int i=1;i<=n+m+1;i++) cin>>a[i].second;
    //判断临界点
    int ansf=0,anss=0,cntf=0,cnts=0;
    int pos=0,kd=0; 
    int lin=0;
    for(int i=1;i<=n+m+1;i++){
        if(n==0) kd=1;
        else kd=2;
        if(cntf<n&&cnts<m){
            if(a[i].first>a[i].second){
                cntf++;
                ansf+=a[i].first;
                kd=1;
            }else{
                cnts++;
                anss+=a[i].second;       
                kd=2;
            }
        }else{
            if(cntf==n) anss+=a[i].second;
            else if(cnts==m) ansf+=a[i].first;
            if(!pos){
                pos=i;
            }
        }
    }
    pos--;
    int pos2=0,kd2=0;
    cntf=0,cnts=0;
    for(int i=2;i<=n+m+1;i++){
        if(n==0) kd=1;
        else kd=2;
        if(cntf<n&&cnts<m){
            if(a[i].first>a[i].second){
                cntf++;
                ansf+=a[i].first;
                kd2=1;
            }else{
                cnts++;
                anss+=a[i].second;       
                kd2=2;
            }
        }else{
            if(cntf==n) anss+=a[i].second;
            else if(cnts==m) ansf+=a[i].first;
            if(!pos2){
                pos2=i;
            }
        }
    }
    cout<<pos<<" "<<kd<<endl;
    cout<<pos2<<" "<<kd2<<endl;
    //这里固定了pos,kd,再找下一个pos,kd;
    for(int i=1;i<=n+m+1;i++){
        int tmp=ansf+anss;
        if(kd==1){
            if(i<=pos){
                tmp-=max(a[i].first,a[i].second);
                if(a[pos+1].first>a[pos+1].second) tmp+=(a[pos+1].first-a[pos+1].second);    
                cout<<tmp<<" ";
            }else{
                tmp-=a[i].second;
                cout<<tmp<<" ";
            }
        }else{
            if(i<=pos){
                tmp-=max(a[i].first,a[i].second);
                if(a[pos+1].first<=a[pos+1].second) tmp+=(a[pos+1].second-a[pos+1].first);    
                cout<<tmp<<" ";
            }else{
                tmp-=a[i].first;
                cout<<tmp<<" ";
            }
        }
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}