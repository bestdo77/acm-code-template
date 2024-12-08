#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int MAXN=1e3+10;
int cnt[1100000];
bool cmp(int x,int y){
    return x>y;
}
vector<int> b[1100000];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    int depth=0;
    for(int i=1;i<=n;++i){
        int x;cin>>x;
        b[x].push_back(i);
        if(x!=0) cnt[i]=1;
        depth=max(x,depth);
    }
    bool flag=1;
    if(b[0].size()!=1) flag=0;
    for(int i=2;i<=depth;++i){
        if(b[i].size()>b[i-1].size()*(k-1)){
            flag=0;break;
        }
    }
    if(b[1].size()>k) flag=0;
    if(flag){
        cout<<n-1<<endl;
        for(int i=depth-1;i>=0;i--){
            int p=0;
            for(int j=0;j<b[i+1].size();++j){
                if(cnt[b[i][p]]<k){
                        cnt[b[i][p]]++;
                        cout<<b[i][p]<<" "<<b[i+1][j]<<endl;
                   }else{
                        p++;
                        cout<<b[i][p]<<" "<<b[i+1][j]<<endl;
                        cnt[b[i][p]]++;
                }
            }
        }
    }else{
        cout<<-1<<endl;
    }
    return 0;
}