#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int n,m,q;
vector<int> col[N];
void Atomatic_AC_machine(){
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        col[i].push_back(0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;cin>>x;
            x|=col[j].back();
            col[j].push_back(x);
        }
    }
    while(q--){
        int qq;cin>>qq;
        int l=1,r=n;
        while(qq--){
            int cl,val;
            char dir;
            cin>>cl>>dir>>val;
            // cout<<cl<<" "<<dir<<" "<<val<<endl;
            if(dir=='<'){
                int pos1=(lower_bound(col[cl].begin(),col[cl].end(),val)-col[cl].begin())-1;
                // cout<<"<"<<" "<<pos1<<endl;
                r=min(r,pos1);
            }else{
                int pos2=(upper_bound(col[cl].begin(),col[cl].end(),val)-col[cl].begin());
                // cout<<"> "<<pos2<<endl;
                l=max(l,pos2);
            }
            // cout<<l<<" "<<r<<endl;
        }
        if(l<=r) cout<<l<<endl;
        else cout<<-1<<endl;
    }
    for(int i=1;i<=m;i++){
        col[i].clear();
    }
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