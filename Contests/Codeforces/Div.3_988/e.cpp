#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
// #define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int query(int r){
    cout<<"? 1 "<<r<<endl;
    int x;cin>>x;
    return x;
}
int ans[N];                             
void Atomatic_AC_machine(){
    int n;cin>>n;
    string s="";
    int last=0;
    for(int i=2;i<=n;i++){
        ans[i]=query(i);
    }
    int pos=0;
    for(int i=2;i<=n;i++){
        if(ans[i]!=0){
            pos=i;
            break;
        }
    }
    // if(n<=2&&ans[2]!=1){
    //     cout<<"! IMPOSSIBLE"<<endl;
    //     return;
    // }else if(n==2&){

    // }
    if(pos==0){
        cout<<"! IMPOSSIBLE"<<endl;
        return;
    }
    for(int i=1;i<=pos-ans[pos]-1;i++){
        s.push_back('1');
    }
    for(int i=1;i<=ans[pos];i++){
        s.push_back('0');
    }
    s.push_back('1');
    for(int i=pos+1;i<=n;i++){
        if(ans[i]>ans[i-1]){
            s.push_back('1');
        }else{
            s.push_back('0');
        }
    }
    // cout<<pos<<endl;
    cout<<"! "<<s<<endl;
}   
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}