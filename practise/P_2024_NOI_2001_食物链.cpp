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
int a[N];
int f[N];
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
    int cnt=0;
    init(3*n);
    for(int i=1;i<=m;i++){
        int op,x,y;cin>>op>>x>>y;
        if(x>n||y>n){
            cnt++;
            continue;
        }
        if(op==1){//x,y同类
            if(find(x+n)==find(y)||find(x+2*n)==find(y)) cnt++;//如果x,y本身有其它关系,那么就是假话
            else join(x,y),join(x+n,y+n),join(x+2*n,y+2*n);
        }else{
            if(x==y){
                cnt++;
                continue;
            }
            if(find(x)==find(y)||find(x+2*n)==find(y)) cnt++;
            else join(x,y+2*n),join(x+n,y),join(x+2*n,y+n);//x的同类是y的天敌,x的猎物是y,x的天敌是y的食物
        }
    }
    cout<<cnt<<endl;
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