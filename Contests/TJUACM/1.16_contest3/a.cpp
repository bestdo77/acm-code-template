#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
#define debug(x) cout<<x<<endl;
void print(vector<int> a){
    for(auto it:a) cout<<it<<" ";
    cout<<endl;
}
set<int> st;
void Atomatic_AC_machine(){
    string s;cin>>s;
    int cer=0,que=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='o') cer++;
        else if(s[i]=='?') que++;
    }
    int ans=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int p=0;p<=9;p++){
                    set<int> sb;
                    sb.insert(i);
                    sb.insert(j);
                    sb.insert(k);
                    sb.insert(p);
                    int sum=0;
                    for(auto it:sb){
                        if(s[it]=='o') sum++;
                    }
                    if(sum!=cer) continue;
                    if(s[i]=='x') continue;
                    if(s[j]=='x') continue;
                    if(s[k]=='x') continue;
                    if(s[p]=='x') continue;
                    int x=i*1000+j*100+k*10+p;
                    st.insert(x);
                }
            }
        }
    }
    cout<<st.size()<<endl;
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