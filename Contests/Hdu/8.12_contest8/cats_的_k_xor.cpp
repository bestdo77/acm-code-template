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
// int a[N];
vector<int> G;
vector <int>kn;
stack<int>sa,sb;
int a,b,c;
int calc(int k){
    //cout<<a<<" "<<b<<" "<<k<<endl;
    kn.push_back(k);
    int ans=0;
    int tem=1;
    int tema=a,temb=b;
    while (tem<mod){
        tem*=k;
        sa.push(tema%tem);
        tema-=tema%tem;
        sb.push(temb%tem);
        temb-=temb%tem;
    }
    while (tem>1){
       // cout <<sa.top()<<" "<<sb.top()<<endl;;
        ans+=(sb.top()+sa.top());
        sa.pop();sb.pop();
        tem/=k;
    }
    // cout <<endl<<k<<" "<<ans<<endl;
    if (ans!=a+b){
        cout<<ans<<endl;
        cout<<"opps"<<endl;
        return 1;
    }
    else return 0;
}
void solve(){
    cin>>a>>b>>c;
    int p=a+b-c;
    int cnt=0;
    if(p==0){
        cout<<-1<<endl;
        return;
    }else if(p<0){
        cout<<0<<endl;
        return;
    }
    int tmp=1;
    for(int i=2;i<=sqrt(p);i++){
        int x=a,y=b;
        if(p%i==0){
            cnt+=calc(i);
            if((p/i)!=i)cnt+=calc(p/i);
        }
    }
    if(p!=1) cnt+=calc(p);
    cout<<cnt<<endl;
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