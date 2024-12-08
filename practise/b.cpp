#include <iostream>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int ans=0;
int n,k;
void dfs(int num,int pos,int mx){//剩几个苹果剩几个盘子当前盘子最多能放多少个
    // cout<<num<<" "<<pos<<" "<<mx<<endl;
    if(pos>k) return;
    if(num==0){ 
        ans++;
        return;
    }
    for(int i=num;i>=0;i--){//拿了num个
        if(i>mx) continue;
        dfs(num-i,pos+1,i);//最多不会超过当前num
    }
}
void Atomatic_AC_machine(){
    cin>>n>>k;
    ans=0;
    dfs(n,0,n);
    cout<<ans<<endl;
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