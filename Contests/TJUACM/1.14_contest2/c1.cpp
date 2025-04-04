#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int C[N],r[N];
struct pii
{
    int first,second;
};

bool cmp(pii a,pii b){
    if(a.first==b.first) return a.second>b.second;
    else return a.first<b.first;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    string s;cin>>s;
    int cnt=0;
    int mx=0;
    int lst=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='o'){
            cnt++;
        }else{
            lst=1;
            mx=max(mx,cnt);
            cnt=0;
        }
    }
    if(lst) mx=max(mx,cnt);
    if(mx!=0) cout<<mx<<endl;
    else cout<<-1<<endl;
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