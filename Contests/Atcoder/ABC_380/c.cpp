#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
int id;
pair<int,int> a[N];
void Atomatic_AC_machine(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    int l=0,r=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            if(l<=r&&s[l]=='1'&&s[r]=='1'){
                a[++id]={l,r};
            }
            l=i;
            r=i;
        }else{
            if(s[l]=='0') l++;
            r++;
        }
    }
    if(l<=r&&s[l]=='1'&&s[r]=='1'){
        a[++id]={l,r};
    }
    string ss=s.substr(a[k].first,a[k].second-a[k].first+1);
    s.erase(a[k].first,a[k].second-a[k].first+1);
    s.insert(a[k-1].second,ss);
    cout<<s<<endl;
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