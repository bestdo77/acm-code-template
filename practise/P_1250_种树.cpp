#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// #define pii pair<int, int>
#define endl '\n'
const int N=5e6+10;
const int mod=1e9+7;
// pii a[N];
int lowb[N],cnt;
bool tree[N];
struct pii{
    int first,second,lowb;
}a[N];
bool cmp(pii a,pii b){
    return a.second<b.second;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    memset(tree,false,sizeof(tree));
    for(int i=1;i<=m;i++){
        cin>>a[i].first>>a[i].second;   
        cin>>a[i].lowb;
    }
    sort(a+1,a+m+1,cmp);
    // for(int i=1;i<=m;i++){
    //     cout<<a[i].first<<" "<<a[i].second<<" "<<lowb[i]<<" "<<endl;
    // } 
    for(int i=1;i<=m;i++){
        int l=a[i].first,r=a[i].second;
        int tmp=0;
        for(int j=l;j<=r;j++) if(tree[j]) tmp++;
        
        if(tmp<a[i].lowb){
            for(int j=r;j>=l;j--){
                if(!tree[j]){
                    cnt++;
                    tree[j]=true;
                    tmp++;
                }
                if(tmp==a[i].lowb) break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}