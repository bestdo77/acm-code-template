#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int f[N<<1];
string ch[N];
i64 ksm(i64 x,i64 y){
    i64 re=1;
    while(y){
        if(y&1) re=re*x%mod;
        x=x*x%mod,y/=2;
    }
    return re;
}
void init(int n){
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
}
int find(int x){
    if(x!=f[x]) return f[x]=find(f[x]);
    return f[x];
}
void join(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy) f[fy]=fx;
}
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    init(2*n);
    for(int i=1;i<=n;i++){
        cin>>ch[i];
        ch[i]=" "+ch[i];
    }
    int cnt=0;
    //遍历每一列
        
    for(int i=1;i<=m/2;i++){
        int l=0,r=0,mid=0;
        int cnt=0;
        for(int j=1;j<=n;j++){
            // cout<<i<<" "<<m-i+1<<endl;
            if(ch[j][i]=='1'&&ch[j][m-i+1]=='1'){
                if(l||r){
                    cout<<0<<endl;
                    return;
                }else{
                    // join(j,j+n);
                    l=r=i;
                }
                cnt+=2;
            }else if(ch[j][i]=='1'){//左侧为1
                if(l){
                    if(find(l)==find(j)){//要翻转,但是已经有了不反转的关系
                        cout<<0<<endl;
                        return;
                    }else{
                        join(l,j+n);
                        join(l+n,j);
                    }
                }
                if(r){
                    if(find(r+n)==find(j)){//不翻转,但是有了要反转的关系
                        cout<<0<<endl;
                        return;
                    }else{
                        join(r,j);
                        join(r+n,j+n);
                    }
                }
                l=j;
                cnt++;
            }else if(ch[j][m-i+1]=='1'){
                if(r){
                    if(find(r)==find(j)){//要反转,但是有了不反转的关系
                        cout<<0<<endl;
                        return;
                    }else{
                        join(r,j+n);
                        join(r+n,j);
                        // cout<<l<<endl;
                    }
                }
                if(l){
                    if(find(l+n)==find(j)){//不翻转,但是有了要反转的关系
                        cout<<0<<endl;
                        return;
                    }else{
                        join(l,j);
                        join(l+n,j+n);
                    }
                }
                r=j;
                cnt++;
            }
            if(cnt>2){
                cout<<0<<endl;
                return;
            }
        }
    }
    if(m%2){
        for(int j=1;j<=n;j++){
            if(ch[j][m/2+1]=='1') cnt++;
        }
    }
    if(cnt>=2){
        cout<<0<<endl;
        return;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i) ans++;
    }
    // for(int i=1;i<=2*n;i++){
    //     cout<<find(i)<<" ";
    // }cout<<endl;

    cout<<ksm(2,ans)<<endl;   
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}