#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<int> a;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    // for(auto it:a){
    //     cout<<it<<" ";
    // }cout<<endl;
    reverse(a.begin(),a.end());
    while(a.size()!=1){
        int x=a[a.size()-1];
        a.pop_back();
        int y=a[a.size()-1];
        a.pop_back();
        // cout<<x<<" "<<y<<endl; 
        a.push_back((x+y)/2);
    }
    cout<<a[0]<<endl;
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