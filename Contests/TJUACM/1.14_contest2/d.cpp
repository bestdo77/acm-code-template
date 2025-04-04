#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=2e3+10;
const int mod=1e9+7;
vector<int> pre[200];
vector<int> sum[200];
vector<int> sum100;
int a[N];
int vis[N1][N1];
void print(vector<int> a,vector<int> b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout<<"Yes"<<endl;
    cout<<a.size()<<" ";
    for(auto it:a){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<b.size()<<" ";
    for(auto it:b){
        cout<<it<<" ";
    }
    cout<<endl;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        a[i]%=200;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<200;j++){
            pre[j]=sum[j];
        }
        if(pre[0].size()){
            vector<int> tt;
            vector<int> b=pre[0];
            b.emplace_back(i);
            tt.emplace_back(i);
            print(tt,b);
            return;
        }
        if(pre[a[i]].size()){
            vector<int> tt=pre[a[i]];
            vector<int> b;
            b.emplace_back(i);
            print(tt,b);
            return;
        }else{
            sum[a[i]].emplace_back(i);
        }
        for(int j=0;j<200;j++){
            if(pre[j].size()){
                if(pre[(a[i]+j)%200].size()==0){//a[i]+j，如果之前的已经有了，
                    pre[j%200].emplace_back(i);
                    sum[(a[i]+j)%200]=pre[(j)%200];
                    pre[j%200].pop_back();
                }else{
                    vector<int> tt=pre[(j+a[i])%200];
                    vector<int> b=pre[j%200];
                    b.emplace_back(i);
                    print(tt,b);
                    return;
                }
            }
        }
        for(int j=0;j<200;j++){
            if(sum[j].size()==0) sum[j]=pre[j];
        }
    }
    cout<<"No"<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}