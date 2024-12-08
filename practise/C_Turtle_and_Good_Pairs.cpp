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
vector<int> G[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    string s;cin>>s;
    vector<int> ch(26);
    for(int i=0;i<n;i++){
        ch[s[i]-'a']++;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            if(ch[j]) {
                cout<<char(j+'a');
                ch[j]--;
            }
        }
    }
    cout<<endl;
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